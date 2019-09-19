module ListModules = [%graphql
  {|
    query modules {
      modules {
        name
        id
        description
      }
    }
  |}
];