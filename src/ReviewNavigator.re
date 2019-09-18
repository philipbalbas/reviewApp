open ReactNavigation;
open ReactNative;

module LectureNavigator = {
  let navigator =
    StackNavigator.make({"Modules": Modules.make, "Lecture": Lecture.make});
};

module MainNavigator =
  AppContainer.Make({
    type screenProps = unit;
    let navigator =
      DrawerNavigator.make({
        "Lecture": LectureNavigator.navigator,
        "MealDetail": Lecture.make,
      });
  });

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
    })
  );

[@react.component]
let make = () => <MainNavigator />;