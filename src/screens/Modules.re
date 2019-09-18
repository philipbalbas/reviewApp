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
    <Text> "Module Screen"->React.string </Text>
    <Button
      title="Go to Subjects"
      onPress={_ => navigation->Navigation.navigate("Subjects")}
    />
  </View>;
};

make->NavigationOptions.(
        setNavigationOptions(
          t(
            ~title="Modules",
            // TODO: Center header title
            // ~headerTitleStyle=Style.(style(~alignSelf=`center, ~flex=1., ())),
            (),
          ),
        )
      );