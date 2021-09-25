# Costom
- `./philo 5 610 200 200`  : 무한루프
- `./philo 5 410 200 200`  : 죽음
- `./philo 4 410 200 200`  : 무한루프
- `./philo 200 410 200 200`  : 무한루프

# Evaluation
- 1 800 200 200, the philosopher should not eat and should die!
- 5 800 200 200, no one should die!
- 5 800 200 200 7, no one should die and the simulation should stop when all the philosopher has eaten at least 7 times each.
- 4 410 200 200, no one should die!
- 4 310 200 100, a philosopher should die!
- Test with 2 philosophers and check the different times

# Test
- `./philo 5 800 200 200 7 | grep "1 is eating"`
- -> 위의 경우, eating 이 나오고 다른 메세지가 출력되지 않고 바로 종료 되어야한다.