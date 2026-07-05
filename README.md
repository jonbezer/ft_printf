*This project has been created as part of the 42 curriculum by jonbezer.*

# ft_printf

## Descrição

`ft_printf` é uma reimplementação da função `printf()` da biblioteca padrão do C, construída como uma biblioteca estática (`libftprintf.a`). O objetivo é reproduzir o comportamento central de formatação e saída do original, sem utilizar os mecanismos de buffer da libc.

O projeto introduz **funções variádicas** em C — funções que aceitam um número variável de argumentos — utilizando as macros de `<stdarg.h>`: `va_list`, `va_start`, `va_arg`, e `va_end`.

As seguintes conversões são suportadas:

| Especificador | Saída |
|---------------|-------|
| `%c` | Caractere único |
| `%s` | String (imprime `(null)` se o ponteiro for NULL) |
| `%p` | Endereço do ponteiro em hexadecimal (`0x...`), imprime `(nil)` se NULL |
| `%d` | Inteiro decimal com sinal (base 10) |
| `%i` | Inteiro com sinal (base 10) |
| `%u` | Inteiro decimal sem sinal (base 10) |
| `%x` | Número sem sinal em hexadecimal (base 16) — letras em minúsculas (ex: `ff`) |
| `%X` | Número sem sinal em hexadecimal (base 16) — letras em maiúsculas (ex: `FF`) |
| `%%` | Sinal de porcentagem literal |

A função retorna o número total de caracteres escritos na stdout, igualando o comportamento do `printf()` original.

---

## Algoritmo e Estrutura de Dados

A implementação segue uma arquitetura limpa de três camadas, cada uma com responsabilidade única:

**Camada 1 — `ft_printf` (orquestrador)**
Itera pela format string caractere por caractere usando um loop `while` com ponteiro. Quando um `%` é encontrado seguido de um caractere válido, delega para `ft_format`, passando o especificador e um ponteiro para o `va_list` (`va_list *`). Todos os outros caracteres são escritos diretamente via `ft_print_chr`. A contagem total de caracteres é acumulada e retornada.

**Camada 2 — `ft_format` (despachante)**
Recebe o caractere especificador e um `va_list *`. Usa uma cadeia de condições `if` para identificar o especificador e chamar o helper correspondente, extraindo o próximo argumento variádico com `va_arg(*args, tipo)` no ponto exato da chamada. Passar `va_list` por ponteiro (`va_list *`) em vez de por valor é uma decisão deliberada de portabilidade: em plataformas onde `va_list` é uma struct (e não um array), passar por valor criaria uma cópia e o avanço do cursor dentro de `ft_format` não seria visível ao chamador. Passar por ponteiro garante que a mutação do estado seja compartilhada independentemente da ABI.

**Camada 3 — helpers de impressão (conversores)**
Cada helper recebe um valor já extraído e é responsável apenas por convertê-lo e escrevê-lo. Não têm nenhum conhecimento sobre argumentos variádicos. Todos retornam o número de caracteres escritos.

A conversão numérica (`%d`, `%i`, `%u`, `%x`, `%X`) é feita recursivamente por decomposição de dígitos: dividindo o número pela base e recursando até restar um único dígito, imprimindo dígito por dígito na volta da recursão. Isso evita a necessidade de um buffer local. Um intermediário `long` é usado em `ft_print_nbr` para tratar `INT_MIN` com segurança, evitando overflow de inteiro com sinal (que seria comportamento indefinido).

---

## Instruções

### Compilação

```bash
make
```

Compila todos os arquivos fonte e cria `libftprintf.a` na raiz do repositório usando `ar rcs`.

### Limpeza

```bash
make clean    # remove os arquivos objeto
make fclean   # remove os arquivos objeto e a biblioteca
make re       # fclean + all
```

### Usando a biblioteca em outro projeto

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o programa
```

Ou incluindo diretamente:

```bash
cc main.c libftprintf.a -o programa
```

No seu arquivo fonte:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Olá, %s! Você tem %d anos%c\n", "Jonathan", 31, '!');
    return (0);
}
```

---

## Recursos

- [Padrão C — ISO/IEC 9899:2011, §7.16: Argumentos variáveis `<stdarg.h>`](https://www.iso.org/standard/57853.html)
- [Linux man page: `printf(3)`](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Linux man page: `stdarg(3)`](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [Linux man page: `va_start`, `va_arg`, `va_end`, `va_copy`](https://man7.org/linux/man-pages/man3/va_start.3.html)

**Uso de IA:** ferramentas de IA foram utilizadas como apoio ao aprendizado durante este projeto — para compreender o modelo conceitual das funções variádicas, a diferença entre passar `va_list` por valor versus por ponteiro, e as implicações de portabilidade de cada abordagem. Todo o código foi escrito pelo estudante. Nenhuma ferramenta de IA foi utilizada para gerar código diretamente.
