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
let make = () => {
  <View style=styles##container>
    <Text> "Profile Screen"->React.string </Text>
  </View>;
};

make->NavigationOptions.(setNavigationOptions(t(~title="Profile", ())));