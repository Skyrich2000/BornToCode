# So_long

## 게임 시작하기
1. 아래 링크를 클론합니다.
```
git clone https://github.com/Skyrich2000/TENET.git
```
2. 아래 명령어를 통해 실행합니다.
```
./tenet
```

## 게임 플레이 방법
* 이동 : `wasd` 혹은 `화살표`로
* 공격 : `space`
* map 다시시작 : `R`
* 종료 : `esc`
* 메인 화면에서 랭킹 보기 : `R`

## 게임 소개
* 영화 TENET을 기반으로한 `타임어택 싱글플레이 퍼즐` 게임
* 게임 캐릭터는 순행플레이어, 역행플레이어, 재순행플레이어가 존재
	* 순행플레이어 : `정상적인 시간 흐름`으로 플레이
	* 역행플레이어 : 시간을 `되돌아가는` 플레이
	* 재순행플레이어 : `정상적인 시간 흐름`으로 플레이
* 각 플레이어가 볼 때, 자신의 시간과 반대로 흐르는 캐릭터는 `거꾸로` 움직입니다

**상태창 위 본인 닉네임 옆에 현재 자신이 조종하고 있는 플레이어의 상태가 표시됩니다**

## 사운드가 안꺼질 때
```
pkill afplay # afplay 프로세스를 종료시켜주세요
```

# 게임 구상

## 게임 로직
* 순행이 금을 다 모아야 탈출 할 수 있다.
* 순행이 상자를 부술 수 있다.
* 좀비는 역행이 무조건 살려야한다.
* 순행 인버터를 타면 시간이 거꾸로 흐르면서 역행 플레이어를 조종한다.
* 역행 인버터는 시간이 음수가 되야 탈 수 있다.
* 역행 인버터를 타면 시간이 다시 순행으로 흐르면서 재순행 플레이어를 조종한다.
* 재순행 플레이어는 탈출구에 가면 탈출 할 수 있다.
* 정해진 색깔과 상호작용 할 수 있다.
* R 를 눌러서 게임을 재시작 할 수 있다.

## 맵 고민
* map 0_0 : map.ber
* map 0_1 : 순행이 자유롭게 돌아다니고, 역행이 그걸 보면서 시간이 거꾸로 흐른다는걸 이해시킨다. + 시간이 음수가 되야 탈 수 있다는걸 어필한다.
* map 0_2 : 순행, 역행, 재순행 모두 탈출구에 접근 가능한 구조 -> 여기서 재순행만 탈출이 가능하다는걸 어필한다. + 서로 충돌하면 안된다는걸 어필한다.
* map 0_3 : 빨간 파란 상자 부수는 맵
* map 0_4 : 좀비 살리는 맵
* map 0_5 : 순행이 좀비 박으면 죽는다는걸 알리는 맵
* map 1 : 쉬운 맵
* map 2 : 근본 맵 1
* map 3 : 근본 맵 2
* map 4 : 어려운 맵
* map 5 : 대 근본 맵

## 이슈

* 인버터에서 공격하면 버그남!
* 맵 파일 분리
* 맵 에디터 추가..?

# Engine

## asset

* background
* font
* map
* object
* scene
* sprite
* script

## game cycle

1. game start
2. scene start
3. scene controller
4. draw background
5. instance draw
6. instance step
7. scene ui
8. back to 3
9. scene end
10. back to 2
11. game end


## instance life cycle

1. create
2. step
3. draw
4. back to 2
5. destory
