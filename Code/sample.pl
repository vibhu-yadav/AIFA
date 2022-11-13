concat([],L,L).

concat([X|L1],L2,[X|L3]):-
    concat(L1,L2,L3).

member(X,[X|_]).

member(X,[_|Tail]):-
    member(X,Tail).


del(X,[X|L],L).

del(X,[Y|L1],[Y|L2]):-
    del(X,L1,L2).


ordered_list([]).

ordered_list([X]).

ordered_list([H]|Tail):-
    H < H1,
    concat([H1],Tail1,Tail),
    ordered_list([H1]|Tail1).

partition(X,List,Before,After):-
    concat(Before,[X|After],List).

before_after(X,L,B,A):-
    concat(_,[B,X,A|_],L).

max_list([X],X).

max_list([H|Tail],N):-
    max_list(Tail,N1),
    H > N1,
    N is H.

max_list([H|Tail],N):-
    max_list(Tail,N1),
    H =< N1,
    N is N1.

