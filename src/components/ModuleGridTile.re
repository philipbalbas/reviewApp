open ReactNative;
open Expo;

let styles =
  Style.(
    StyleSheet.create({
      "gridItem":
        style(
          ~flex=1.,
          ~margin=15.->dp,
          ~height=153.->dp,
          ~borderRadius=10.,
          ~overflow={
            Platform.os == Platform.android ? `hidden : `visible;
          },
          ~elevation=5.,
          (),
        ),
      "container":
        style(
          ~flex=1.,
          ~borderRadius=10.,
          ~shadowColor="black",
          ~shadowOpacity=0.26,
          ~shadowOffset=offset(~width=0., ~height=2.),
          ~shadowRadius=10.,
          ~padding=15.->dp,
          ~justifyContent=`center,
          ~alignItems=`center,
          ~backgroundColor="#5D25A4",
          (),
        ),
      "title": style(~fontSize=22., ~textAlign=`center, ~color="#fff", ()),
    })
  );

[@react.component]
let make = (~name, ~onPress) => {
  <View style=styles##gridItem>
    <TouchableOpacity onPress style=Style.(style(~flex=1., ()))>
      <LinearGradient
        colors=[|"#6CBBF5", "#5B139A"|]
        start=[|0.1, 0.2|]
        _end=[|1.0, 1.5|]
        style=styles##container>
        <Text style=styles##title> name->React.string </Text>
      </LinearGradient>
    </TouchableOpacity>
  </View>;
};