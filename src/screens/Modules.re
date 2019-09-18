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
          ~backgroundColor="#F5FCFF",
          (),
        ),
      "instructions": style(~textAlign=`center, ~color="#ffffff", ()),
    })
  );

[@react.component]
let make = () => {
  <View style=styles##container>
    <Text> "Module Screen"->React.string </Text>
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