Carlos Felipe Pereira Bellomo - M2

Trabalho Avaliativo agenda pBuffer

Resumo: acabei realizando o trabalho 2x, pois de primeira não havia entendido que teria que ser 100% dinâmico. Fiz um tamanho fixo para todos usuários.
Na segunda vez fiz no modelo correto, 100% dinâmico apenas com maloc de início estático, para ter uma referência.

Dificuldades: 
- Na parte de deletar, demorei um tempo para entender o cálculo de bytes que precisava ser feito para utilizar a função memmmove, mas a lógica para implementação consegui pegar rápido.

- Ao fazer o teste no Valgrind, estava tendo um leak de memória, no qual demorei bastante tempo para resolver, sendo basicamente a grande dificuldade do meu trabalho. No vídeo demonstrei o que estava dando errado, e como fiz para resolver. 