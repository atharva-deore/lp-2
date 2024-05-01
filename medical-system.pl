diagnose_illness(Symptoms, cold) :-
    member(headache, Symptoms),
    member(runny_nose, Symptoms),
    member(sneezing, Symptoms),
    not(member(fever, Symptoms)).


diagnose_illness(Symptoms, sinusitis) :-
    member(facial_pain, Symptoms),
    member(fever, Symptoms),
    member(nasal_congestion, Symptoms).

diagnose_illness(Symptoms, pneumonia) :-
    member(fever, Symptoms),
    member(cough, Symptoms),
    member(shortness_of_breath, Symptoms),
    member(chest_pain, Symptoms).


diagnose(Symptoms, Diagnosis) :-
    diagnose_illness(Symptoms, Diagnosis),
    !. 



