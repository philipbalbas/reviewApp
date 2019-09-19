open ReactNative;
open ReactNavigation;
open ReasonUrql;
open Hooks;
open Queries;

let str = ReasonReact.string;

let styles =
  Style.(
    StyleSheet.create({
      "container":
        style(
          ~flex=1.,
          ~justifyContent=`center,
          ~alignItems=`center,
          ~backgroundColor="#fff",
          (),
        ),
      "instructions": style(~textAlign=`center, ~color="#ffffff", ()),
    })
  );

[@react.component]
let make = (~navigation) => {
  let request = ListModules.make();
  let ({response}, _) = useQuery(~request, ());

  switch (response) {
  | Fetching => <View> <Text> "Fetching"->str </Text> </View>
  | NotFound => <View> <Text> "NotFound"->str </Text> </View>
  | Error(_e) => <View> <Text> "Error"->str </Text> </View>
  | Data(data) =>
    switch (data##modules) {
    | None => <View> <Text> "Please Create a Module"->str </Text> </View>
    | Some(modules) =>
      let modulesList =
          (
            itemData:
              ReactNative.VirtualizedList.renderItemProps(
                option({
                  .
                  "description": option(string),
                  "id": option(string),
                  "name": option(string),
                }),
              ),
          ) => {
        switch (itemData##item) {
        | None => <View> <Text> "NotFound"->str </Text> </View>
        | Some(item) =>
          let id =
            Belt.Option.mapWithDefault(item##id, "Missing id", txt => txt);

          let name =
            Belt.Option.mapWithDefault(item##name, "Missing name", txt => txt);

          <ModuleGridTile
            name
            key=id
            onPress={_ =>
              navigation->Navigation.navigateWithParams(
                "Subjects",
                {"moduleId": id},
              )
            }
          />;
        };
      };

      <FlatList
        data=modules
        numColumns=2
        renderItem=modulesList
        keyExtractor={(item, _) =>
          switch (item) {
          | None => ""
          | Some(module_) =>
            module_##id->Belt.Option.mapWithDefault("", txt => txt)
          }
        }
      />;
    }
  };
};

make->NavigationOptions.(
        setDynamicNavigationOptions(navData =>
          t(~title="Modules", ~headerLeft=Helpers.avatarIcon(navData), ())
        )
      );

NavigationOptions.setDynamicNavigationOptions;