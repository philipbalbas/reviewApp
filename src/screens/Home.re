open ReactNative;
open ReactNavigation;
open Expo;

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
    <Text> "Home Screen"->React.string </Text>
    <View style=Style.(style(~marginTop=11.->dp, ())) />
    <WebView
      source={WebView.Source.uri(
        ~uri="https://facebook.github.io/react-native/",
        (),
      )}
    />
    <Text style=Style.(style(~color="red", ()))> "What"->React.string </Text>
  </View>;
};

make->NavigationOptions.(setNavigationOptions(t(~title="Home", ())));