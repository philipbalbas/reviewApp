open ReactNavigation;

module LectureNavigator = {
  let navigator =
    StackNavigator.make({
      "Modules": Modules.make,
      "Subjects": Subjects.make,
      "Topics": Topics.make,
      "Notes": Notes.make,
    });
};

module BottomNavigator = {
  let navigator =
    TabNavigator.Bottom.make({
      "Home": Home.make,
      "Lecture": LectureNavigator.navigator,
      "Quiz": Quiz.make,
      "Exam": Exam.make,
    });
};

module MainNavigator =
  AppContainer.Make({
    type screenProps = unit;
    let navigator =
      DrawerNavigator.make({
        "LectureQuiz": BottomNavigator.navigator,
        "Profile": Profile.make,
      });
  });

[@react.component]
let make = () => <MainNavigator />;