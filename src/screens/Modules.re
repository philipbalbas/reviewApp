open ReactNative;
open ReactNavigation;
open Helpers;

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
        setDynamicNavigationOptions(navData =>
          t(~title="Modules", ~headerLeft=Helpers.avatarIcon(navData), ())
        )
      );

NavigationOptions.setDynamicNavigationOptions;