## Euclid

A rudimentary number theory playground in C and Haskell.

### Functionality
|                               | C             | Haskell       |
| ----------------------------- | ------------- | ------------- |
| Standard Euclidean Algorithm  | ✅            | ✅            |
| Extended Euclidean Algorithm  | ❌            | ❌            |
| Bezout Identity               | ❌            | ❌            |
| Coprime test                  | ❌            | ✅ (No CLI)   |
| Num. coprimes from 1 to n     | ❌            | ✅ (No CLI)   |

Currently the only command line functionality is computing the GCD of an
arbitrarily long list of numbers. All Haskell functionality marked with "No
CLI" requires the use of an interpreter such as `gchi`.

### Usage

To compile, use `make compile`. This will produce two equivalent executables,
`c.out` and `hs.out`. To compute the GCD of a list of numbers, use

```
./c.out [n1 n2 n3 ... ]
```

or

```
./hs.out [n1 n2 n3 ... ]
```

### Requirements

 - `gcc`
 - `ghc`
 - `make`

