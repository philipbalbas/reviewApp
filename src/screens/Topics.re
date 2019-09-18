open ReactNative;
open ReactNavigation;

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
  <View style=styles##container>
    <Text> "Topic Screen"->React.string </Text>
    <Button
      title="Go to Note"
      onPress={_ => navigation->Navigation.navigate("Notes")}
    />
  </View>;
};

make->NavigationOptions.(
        setNavigationOptions(
          t(
            ~title="Topics",
            // TODO: Center header title
            // ~headerTitleStyle=Style.(style(~alignSelf=`center, ~flex=1., ())),
            (),
          ),
        )
      );