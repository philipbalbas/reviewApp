open ReactNative;
open ReactNavigation;

let headerIcon = (~style as additionalStyle=Style.style(), source) =>
  <Image
    style=Style.(
      array([|
        style(~width=24.->dp, ~margin=11.->dp, ~height=24.->dp, ()),
        additionalStyle,
      |])
    )
    source
  />;

let tabBarIcon = source =>
  NavigationOptions.TabBarIcon.render(props =>
    <Image
      style=Style.(
        style(
          ~tintColor=props##focused ? "#1da1f2" : "grey",
          ~width=24.->dp,
          ~margin=11.->dp,
          ~height=24.->dp,
          (),
        )
      )
      source
    />
  );

let avatarIcon = params =>
  <TouchableOpacity onPress={_ => params##navigation->Navigation.openDrawer}>
    <Image
      style=Style.(
        style(
          ~backgroundColor="#fff",
          ~width=24.->dp,
          // ~borderRadius=12.,
          ~margin=11.->dp,
          ~height=24.->dp,
          (),
        )
      )
      source=Icons.menu
    />
  </TouchableOpacity>;