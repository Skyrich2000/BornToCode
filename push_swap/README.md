# push_swap

## Simple test

```
ARG=`ruby -e "puts (0..10).to_a.shuffle.join(' ')"`; ./push_swap $ARG
```

## Checker Usage
```
ARG=`ruby -e "puts (0..10).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
```

## Tester

```
make test
```

[Tester from minckim](https://github.com/minckim42/push_swap_tester)