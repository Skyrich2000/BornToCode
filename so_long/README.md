
## TODO

* 재순행 공격 못하게 막기

* 게임 로직
	* 순행이 금을 다 모아야 탈출 할 수 있다.
	* 순행이 상자를 부술 수 있다.
	* 좀비는 역행이 무조건 살려야한다.
	* 순행 인버터를 타면 시간이 거꾸로 흐르면서 역행 플레이어를 조종한다.
	* 역행 인버터는 시간이 음수가 되야 탈 수 있다.
	* 역행 인버터를 타면 시간이 다시 순행으로 흐르면서 재순행 플레이어를 조종한다.
	* 재순행 플레이어는 탈출구에 가면 탈출 할 수 있다.
	* 정해진 색깔과 상호작용 할 수 있다.
	* R 를 눌러서 게임을 재시작 할 수 있다.

* 튜토리얼 고민
	* map 0_0 : map.ber
	* map 0_1 : 순행이 자유롭게 돌아다니고, 역행이 그걸 보면서 시간이 거꾸로 흐른다는걸 이해시킨다. + 시간이 음수가 되야 탈 수 있다는걸 어필한다.
	map = sl_split("\
1111111111111111 \
10000000000000E1 \
1011111111111111 \
1000000000000001 \
1111111111111101 \
100C0000C000C101 \
1000000000000101 \
1P0000C000C000C1 \
1111111111111111", ' ');

	* map 0_2 : 순행, 역행, 재순행 모두 탈출구에 접근 가능한 구조 -> 여기서 재순행만 탈출이 가능하다는걸 어필한다.
	map = sl_split("\
1111111111111111 \
1000000000000001 \
1011111111111101 \
1010001000B000C1 \
1010101011111101 \
101010100B00B011 \
1010101110111001 \
10001E1P000B00B1 \
1111111111111111", ' ');

	* map 0_3 : 빨란 파란 금 먹는 맵
	* map 0_4 : 빨간 파란 상자 부수는 맵
	* map 0_5 : 빨간 파란 좀비 살리는 맵
	* map 0_6 : 순행이 좀비 박으면 죽는다는걸 알리는 맵
	* map 1 : 이제 근본 맵 시작
	
```c
func[(int)'1'] = create_wall_instance;
func[(int)'Z'] = create_zombie_blue_instance;
func[(int)'3'] = create_zombie_red_instance;
func[(int)'B'] = create_box_red_instance;
func[(int)'4'] = create_box_blue_instance;
func[(int)'C'] = create_gold_red_instance;
func[(int)'5'] = create_gold_blue_instance;
func[(int)'E'] = create_exit_instance;
func[(int)'P'] = create_player_instance;
```	
map = sl_split("\
11111111111 \
10000100001 \
10000C00101 \
10000500101 \
1P000100001 \
11111111111", ' ');

# engine

## asset

* background
* font
* sprite
* object
* scene
* script

## game cycle

1. game start
2. scene start
3. scene controller
4. instance step
5. draw background
6. instance draw
7. back to 3
8. scene end
9. back to 2
10. game end


## instance life cycle

1. create
2. step
3. draw
4. back to 2
5. destory

## 게임 시작하기
1. 아래 링크를 클론합니다.
```
git clone [주소]
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
pkill afplay // afplay 프로세스를 종료시켜주세요
```

## before

## done
map 1_2
map 1_3
map 2
map 3
map 4
map 5
