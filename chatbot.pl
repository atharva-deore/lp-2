% Define greetings
greeting([hello, hi, hey, greetings, 'howdy!']).

% Define responses to greetings
response(hello, ['hi there!', 'hello!', 'hey!', 'nice to see you!', 'how are you?']).
response(hi, ['hello!', 'hey there!', 'hi!', 'how are you?', 'what can I do for you?']).
response(hey, ['hello!', 'hi!', 'hey there!', 'what can I do for you?', 'nice to see you!']).
response(greetings, ['howdy!', 'hello!', 'hi!', 'what can I do for you?', 'nice to see you!']).
response('howdy!', ['hello!', 'hi!', 'hey!', 'nice to see you!', 'what can I do for you?']).

% Define responses to questions
response('how are you?', ['I am fine, thank you!', 'I am doing well, thanks for asking!', 'I am good, how about you?', 'I am great, how are you?']).
response('what is the weather like?', ['It is sunny today.', 'Looks like it will rain.', 'The weather is pleasant.', 'It is cold outside.']).
response('what is date today?', [Date]) :- get_time(Time), format_time(atom(Date), '%A, %B %d, %Y', Time).
response('what time is it?', [Time]) :- get_time(Time), format_time(atom(Time), '%r', Time).

% Define default response for unknown queries
response(_, ['I am not sure what you mean...', 'Could you please rephrase that?', 'I am just a simple chatbot...', 'I am not equipped to answer that.']).

% Determine appropriate response based on input query
respond(Query, Response) :-
    (var(Query) -> 
        Response = ['I am not sure what you mean...', 'Could you please rephrase that?', 'I am just a simple chatbot...', 'I am not equipped to answer that.']
    ; response(Query, Response), !).

% Main chat interaction loop
chat :-
    write('Chatbot: Hello! How can I help you?'), nl,
    repeat,
    write('You: '),
    read_line_to_codes(user_input, Input),
    atom_codes(Query, Input),
    (Query = bye -> write('Chatbot: Goodbye!'), nl; 
    (greeting(Query) -> random_member(Greeting, Query), write('Chatbot: '), write(Greeting), nl; 
    respond(Query, Response), random_member(Reply, Response), write('Chatbot: '), write(Reply), nl, fail)),
    Query = bye, !.