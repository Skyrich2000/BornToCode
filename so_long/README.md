
## TODO

* 배경 수정
* 좀비 이해시키는 맵 추가
* 파란 빨강 금, 좀비 추가
* 노미네트
* 기다리게 하는거 추가...? 를 어떻게 하면 좋을까
	* time < 0 일때만 inverter 가 활성화 된다.
		* 이걸 어떻게 이해시키지?
			* 이걸 이해시키는 맵을 만든다?
			* 활성화될떄 뭔가 액션을 준다? -> 에셋이 필요하다...? 어떻게 표현 하지?
			* 아직 떄가 아닌데 인버팅을 하려고 하면 기다리라고 띄운다? -> 이게 그나마 할만한듯?
		* 이해 못하면 어떡하지
			* 뭔가 길을 잃을 수 있다?
			* 목적을 읽을 수 있다.
	* 이전처럼 플레이어를 고정시킨다.
		* 근데 이건 간지가 안나는거같아 기각
* 좀비를 하나라도 안죽이면 tenet error

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
