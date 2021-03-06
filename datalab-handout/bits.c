/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /*
  Partimos de los resultados de XOR
  1 XOR 1 = 0
  1 XOR 0 = 1
  0 XOR 1 = 1
  0 XOR 0 = 0

  Luego lo planteamos como proposicion:
  (a ^ ??b) v (??a ^ b)

  Por ??ltimo negamos la proposicion anterior para evitar usar OR
  ~[~(a & ~b) & ~(~a & b)]
  */
  return ~(~(x & ~y) & ~(~x & y));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /*
  El menor n??mero tendr??a la siguiente secuencia
  100...00

  Por ello basta con hacer << 31 de una secuencia
  00...001
  */
  return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  /*
  tmin = 1 << 31 -> 100...00
  tmax = ~(tmin) -> 011...11
  */
  return !(~(1 << 31) ^ x);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /*
  mask = 0xAAAAAAAA -> todos los bits impares por numeraci??n

  Con la operaci??n x & mask los bits impares del resultado ser??n 1
  Para que se cumpla la condici??n
  x & mask = mask
  */
  return !((0xAAAAAAAA & x) ^ 0xAAAAAAAA);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /*
  Tomando en cuenta el siguiente ejemplo
  0010 = 2
  1101 = (-8 + 5) = -3

  Bastar??a con negar la secuencia y sumar 1
  */
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /*
  Sabiendo que:
  a = 0x30
  b = 0x3a

  Adem??s es verdadero si
  (x >= a) && (x < b)

  para determinar si un numero es mayor a otro, los restamos y vemos si es
  negativo o positivo por medio del signo. ya que el signo es positivo
  para una diferencia de 0, se considera que es >=
  x >= a -> !((x + ~a + 1) >> 31)

  del mismo modo si queremos verificar si es menor. pero debemos tomar en cuenta
  que en enteros con signo la operacion >> en negativos a??ade bits 1, en lugar
  de bits 0.
  x < a -> !!((x + ~a + 1) >> 31)
  */
  int a = 0x30;
  int b = 0x3a;

  return (!((x + ~a + 1) >> 31)) & (!!((x + ~b + 1) >> 31));
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /*
  Para este caso consider?? necesario conocer los bits que tenian diferente
  los enteros "y" y "z". El objetivo de esta m??scara es obtener "z" a partir de
  "y" o viceversa.
  A = y ^ z

  dependiendo de x se necesitar?? una m??scara para poder cambiar y operar en los
  enteros (y, z) y conseguir alguno de ellos como respuesta. Debido a que 'x'
  debiera ser verdadero o false se crear?? la m??cara para afectar a todos los
  bits o a ninguno
  B = ~(!!x) + 1
  B -> 00...00 || 11...11

  se utilizar?? la m??scara B para determinar si se cambiar??n los valores de los
  bits en las posiciones determinadas por A o no.
  C -> A & B

  por ??ltimo se hace el cambio de los bits
  D -> z ^ C
  */

  int A = y ^ z;
  int B = ~(!!x) + 1;
  int C = A & B;

  return z ^ C;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /*
  para verificar si es menor se restan los n??meros y se verifica el signo
  A = x < y -> !!((x + ~y + 1) >> 31)

  para verificar si son iguales se opera de la siguiente manera
  B = x == y -> !(x ^ y)

  para evitar el overflow, solo deben compararse los n??meros si tienen el mismo
  signo, de esta manera la diferencia (para x < y) no producir?? overflow. Para
  ello se determina el signo de cada par??metro. Adem??s, si contienen signo
  diferente se puede determinar con facilidad cu??l es mayor o menor.
  si x < 0 -> x >> 31 = 11..11
  si y >= 0 -> y >> 31 = 00...00

  Para que x < y teniendo en cuenta el signo, debe cumplirse la siguiente
  condici??n
  C = (x < 0) & (y >= 0) -> (x >> 31) & ~(y >> 31)
  nota: C tiene la forma 11...11 || 00...00

  por otro lado, C no es suficiente para determinar si tienen diferente signo, por
  ello se plantea la siguiente expresion
  D = C | ~(x >> 31) & (y >> 31)

  En el caso de que tengan el mismo signo se procede a comparar normalmente
  (A).
  !D & A
  */
  
  int A = !!((x + ~y + 1) >> 31); //6
  int B = !(x ^ y); //2
  int C = (x >> 31) & ~(y >> 31); //4
  int D = C | ~(x >> 31) & (y >> 31); //5
  
  return !!C | (!D & A) | B; //6
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /*
  debido a que estamos negando, debe ser 0 para los siguientes valores de 'x'
  x != 0 -> x >= 1 || x < 0

  primero verificamos si x < 0 verificando el signo de 'x'
  A = x < 0 = x >> 31
  nota: A tendra las formas: true 11...11, false 00...00

  A no es suficiente para determinar le negaci??n ya que falta evaluar si 'x' es
  positivo y diferente de 0; es decir, x >= 1.
  C = x >= 1 = (x + ~1 + 1) >> 31
  nota: C true: 00...00
        C false: 11...11

  Por ??timo, aumentamos la precision de la respuesta final, que debera ser 0 si
  x != 0 = RES.
  RES  = (A | ~C) + 1
  */

  int A = x >> 31;
  int C = (x + ~1 + 1) >> 31;
  int RES = (A | ~C) + 1;

  return RES;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /*
  se muestra el siguiente ejemplo
  -5 = 1011b = -8 + 0 + 2 + 1 (4 bits)
  12 = 01100b = -0 + 8 + 4 + 0 + 0 (5 bits)

  pero en realidad es de la siguiente manera
  -5 = 1111 1111 1111 1111 1111 1111 1111 1011 (32 bits)
  12 = 0000 0000 0000 0000 0000 0000 0000 1100 (32 bits)

  adem??s podemos tomar en cuenta que el opuesto de 'x' usa la misma cantidad
  de bits, lo que puede significar una simplificaci??n de la soluci??n del
  problema.
  5 = 0101 = -8 + 4 + 0 + 1 (4 bits)

  se puede observar que para determinar el n??mero de bits m??nimos requeridos es
  necesario separar las secuencias en dos bloques:
  1. bits repetidos de izq a der: (00...00)1...
  2. bits restantes: 00...00(1...)

  de esta manera, podemos determinar que el n??mero minimo de bits requeridos es
  #bits_restantes + 1

  para ello debemos saber cuantos bits restante hay. podria ser posible por
  medio de una mascara que verifique los bits repetidos empezando por verificar
  32 bits, +-16 bits, +-8 bits, etc y reducir hasta verificar el ultimo. se van
  contando los bits en el proceso.
  la mascara seria M, donde los 1 representan el bloque de repetidos
  M = 0xFFFFFFFF
  
  el contador seria count, que empieza en 32
  count = 32

  luego sera necesario una referencia de los bits que seran revisados en cada
  etapa
  b16, b8, b4, b2, b1 -> 16, 8, 4, 2, 1
  */

  int M = 0xFFFFFFFF;
  int count = 32;
  int b16 = 16;
  int b8 = 8;
  int b4 = 4;
  int b2 = 2;
  int b1 = 1;

  int signo = x >> 31;
  x = (signo ^ x) + (~signo + 1); // abs(x)

  int aux = !(M & x); //bloque repetidos encontrado

  M = M >> b16;
  aux = !(M & x);
  return count;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  return 2;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  return 2;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    return 2;
}
