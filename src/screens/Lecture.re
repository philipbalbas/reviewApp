open ReactNative;

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
    <Text> "Lecture Screen"->React.string </Text>
  </View>;
};