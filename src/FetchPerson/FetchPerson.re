[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";
module A = Belt.Array;
module L = Belt.List;

type company = {
  name: string,
  catchPhrase: string,
  bs: string,
};

type geo = {
  lat: string,
  lng: string,
};

type address = {
  street: string,
  suite: string,
  city: string,
  zipcode: string,
  geo,
};

type dataperson = {
  id: int,
  name: string,
  username: string,
  email: string,
  address,
  phone: string,
  website: string,
  company,
};

type state =
  | LoadingPerson
  | ErrorFetchingPerson
  | DataPerson(array(dataperson));

[@react.component]
let make = () => {
  let (state, setState) = React.useState(() => LoadingPerson);

  React.useEffect0(() => {
    Js.Promise.(
      fetch("https://jsonplaceholder.typicode.com/users")
      |> then_(res => res##json())
      |> then_(jsonRes => {
           setState(_prevState => DataPerson(jsonRes));
           Js.Promise.resolve();
         })
      |> catch(_err => {
           setState(_prevState => ErrorFetchingPerson);
           Js.Promise.resolve();
         })
      |> ignore
    );

    None;
  });

  let containerStyle =
    ReactDOMRe.Style.make(
      ~display="flex",
      ~flexWrap="wrap",
      ~justifyContent="space-evenly",
      (),
    );

  let personStyle =
    ReactDOMRe.Style.make(
      ~width="40%",
      ~border="2px solid #48a9dc",
      ~margin="1em",
      ~padding="1em",
      ~textAlign="center",
      (),
    );

  <div style=containerStyle>
    {switch (state) {
     | ErrorFetchingPerson => "An error occurred!"->React.string
     | LoadingPerson => "Loading..."->React.string
     | DataPerson(person) =>
       person
       ->A.mapWithIndex((i, person) => {
           <div key={i->string_of_int} style=personStyle>
             <img
               alt="kittens"
               width="70%"
               src={
                 "https://robohash.org/"
                 ++ person.id->string_of_int
                 ++ "?set=set4&size=200x200"
               }
             />
             <p> "Name: "->React.string person.name->React.string </p>
             <p>
               "Company: "->React.string
               person.company.name->React.string
             </p>
           </div>
         })
       ->React.array
     }}
  </div>;
};
