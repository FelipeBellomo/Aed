Carlos Felipe Pereira Bellomo - M2


143. Reorder List
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.


Complexity = O(n)

Dificuldades:
1- No peŕiodo em aula, comecei desenvolvendo a solução em cima da ideia da utilização de pilha, porém estava criando uma outra lista encadeada para utilizar como stack, o que só vi depois no enunciado que não era permitido. Quando fui começar a resolver de outra maneira, já nao havia tempo, por isso o código de aula ficou enxuto

2- Para minha resolução em casa não quis abrir mão de resolver por stack, porém nao estava conseguindo pensar em uma maneira de criar uma stack sem outra lista.
Então recorri a internet para ver uma maneira de armazenar somente os endereços dos nós.

Solução:
1- Utilizei o link abaixo como base, para utilizar um array como ponteiro para o endereço de cada nó

https://www.reddit.com/r/computerscience/comments/w6o6lk/can_linked_list_be_implemented_using_arrays_as/?tl=pt-br#:~:text=no%20meio%20da%20lista%20sem%20precisar%20mover,tempo%20O(1)%20usando%20indexação%20de%20array%2C%20mas