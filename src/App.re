open ReasonUrql;

let client = Client.make(~url="http://localhost:4000/api", ());

[@react.component]
let app = () => <Provider value=client> <ReviewNavigator /> </Provider>;