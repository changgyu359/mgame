#include <stdio.h>

enum Location
{
	home,
	street,
	conv,
	park,
	burnart,
	arcademy,
	gym,
	inducom,
	boxcen
};

struct Data
{

	int hp;
	int str;
	int intel;
	int money;
	int day;
};

void stat(struct Data data)
{	
	printf(" 날짜:%d\n", data.day);
	printf("체력:%d 근력:%d 지력:%d 돈:%d\n", data.hp, data.str, data.intel, data.money);
}

void locate(enum Location loc)
{
	switch (loc) {
	case home:printf("장소 - 집");
		break;
	case street: printf("장소 - 거리");
		break;
	case conv:printf("장소 - 편의점");
		break;
	case park: printf("장소 - 공원");
		break;
	case burnart: printf("장소 - 번화가");
		break;
	case arcademy: printf("장소 - 학원");
		break;
	}
	printf(" /");
}



//void home()
//{
//	int x = 0;
//
//	printf("장소 - 집\n");
//	printf("체력:%d 근력:%d 지력:%d 돈:%d\n", hp, str, intel, money);
//	printf("1.잠자기-체력을 n회복하고 시간을 진행시킵니다\n");
//	printf("2.공부하기-지력이 n 증가하고 체력이n감소합니다\n");
//	printf("3.운동하기-근력이 n 증가하고 체력이n감소합니다\n");
//	printf("4.거리로 나가기.\n");
//
//	if (x == 1)
//	{
//		hp += 10;
//		printf("잠을 자서 체력을 회복했습니다. 체력:%d\n", hp);
//	}
//	else if (x == 2)
//	{
//		hp -= 3;
//		intel += 2;
//		printf("공부를 하여 지력이 상승하였습니다. 체력:%d 지력%d\n", hp, intel);
//	}
//	else if (x == 3)
//	{
//		hp -= 5;
//		str += 2;
//		printf("운동을 하여 근력이 상승하였습니다. 체력:%d 근력%d\n", hp, str);
//	}
//	else if (x == 4)
//	{
//		street();
//	}
//}
//
//void street()
//{
//	printf("장소 - 거리\n");
//	printf("체력:%d 근력:%d 지력:%d 돈:%d\n");
//	printf("1.편의점\n");
//	printf("2.공원\n");
//	printf("3.번화가\n");
//
//}
//
//void conv()
//{
//	printf("장소 - 편의점\n");
//	printf("체력:%d 근력:%d 지력:%d 돈:%d\n");
//	printf("1.삼각김밥-체력 10회복,1000원\n");
//	printf("2.음료수-체력 5회복,500원\n");
//	printf("3.알바하기-체력을 소모하여 돈을 법니다. 시간이 진행됩니다.\n");
//}
//
//void park()
//{
//	printf("장소 - 공원\n");
//	printf("체력:%d 근력:%d 지력:%d 돈:%d\n");
//	printf("1.벤치에서 쉬기-체력을 조금 회복하고 시간을 약간 진행시킵니다.\n");
//}
//
//
//void burnart()
//{
//	printf("장소 - 번화가\n");
//	printf("체력:%d 근력:%d 지력:%d 돈:%d\n");
//	printf("1.학원-지력50이상 필요.\n");
//	printf("2.체육관-근력50이상 필요.\n");
//}
//
//void arcademy()
//{
//	printf("장소 - 학원\n");
//	printf("체력:%d 근력:%d 지력:%d 돈:%d\n");
//	printf("1.학원 하급반-지력 50필요, 체력을 소모하여 지력을 증가시킵니다.\n");
//	printf("2.학원 상급반-지력 100필요, 체력을 소모하여 지력을 증가시킵니다. 시간이 진행됩니다.\n");
//	printf("3.학원알바-지력 200필요, 체력을 소모하여 돈을 법니다. 시간이 진행됩니다.\n");
//}
//

int main()
{
	struct Data player =
	{
		.hp = 10,
		.str = 200,
		.intel = 0,
		.money = 1000,
		.day=1
	};
	enum Location current = home;
	int choice = 0;
	int coach_met = 0;
	int day7 = 0;
	int bench = 0;
	while (1) {
		if (player.hp <= 0) {
			printf("체력이 없어서 사망했습니다. 게임오버.\n");
			break;
		}
		if (player.day % 7 == 6) {
			day7=1;
		}
		if ((player.day%7==0) & (day7==1)){
			if (player.money < 1000) {
				printf("집세를 낼 돈이 부족하여 쫓겨났습니다. 게임오버.\n");
				break;
			}
			else {
				player.money -= 1000;
				day7=0;
				printf("집세 지불 날입니다. 집세 1000원을 지불합니다.\n");
			}
		}
		locate(current);
		stat(player);
		if (current == home) {
			printf("1.잠자기-체력을 n회복하고 시간을 진행시킵니다.\n");
			printf("2.공부하기-지력이 n 증가하고 체력이n감소합니다.\n");
			printf("3.운동하기-근력이 n 증가하고 체력이n감소합니다.\n");
			printf("4.거리로 나가기.\n");
			scanf_s("%d", &choice);
			printf("\n");
			if (choice == 1) {
				player.hp += 10;
				player.day += 1;
				printf("잠을 자서 체력을 회복했습니다.\n");
			}
			else if (choice == 2) {
				player.hp -= 3;
				player.intel += 2;
				printf("공부를 하여 지력이 상승하였습니다.\n");
			}
			else if (choice == 3) {
				player.hp -= 5;
				player.str += 2;
				printf("운동을 하여 근력이 상승하였습니다.\n");
			}
			else if (choice == 4) {
				current = street;
			}
			else
			{
				printf("잘못된 입력입니다.\n");
			}
		}
		else if (current == street) {
			printf("1.집\n");
			printf("2.편의점\n");
			printf("3.공원\n");
			printf("4.번화가\n");
			scanf_s("%d", &choice);
			printf("\n");

			if (choice == 1) {
				current = home;
			}
			else if (choice == 2) {
				current = conv;
			}
			else if (choice == 3) {
				current = park; 
			}
			else if (choice == 4) {
				current = burnart;
			}
			else
			{
				printf("잘못된 입력입니다.\n");
			}
			
		}
		else if (current == conv) {
			printf("1.삼각김밥-체력 10회복,1000원\n");
			printf("2.음료수-체력 5회복,500원\n");
			printf("3.알바하기-체력을 소모하여 돈을 법니다. 시간이 진행됩니다.\n");
			printf("4.거리로 나가기.\n");
			scanf_s("%d", &choice);
			printf("\n");

			if (choice == 1) {
				if (player.money < 1000) {
					printf("돈이 부족합니다.\n");
				}
				else {
					player.money -= 1000;
					player.hp += 10;
					printf("삼각김밥을 먹었습니다.\n");
				}

			}
			else if (choice == 2) {
				if (player.money < 500) {
					printf("돈이 부족합니다.\n");
				}
				else {
					player.money -= 500;
					player.hp += 50;
					printf("음료수를 마셨습니다.\n");
				}

			}
			else if (choice == 3) {
				player.hp -= 10;
				player.money += 2000;
				player.day++;
				printf("편의점에서 알바를 했습니다.\n");
			}
			else if (choice == 4) {
				current = street;
			}
			else
			{
				printf("잘못된 입력입니다.\n");
			}
		}
		else if (current == park) {
			
			if (player.str >= 200&coach_met==0) {
				printf("=================공원을 걷던 당신에게 누군가 다가왔습니다.=================\n");
				printf("자네 몸이 아주 좋군, 아주 훌륭한 원석이야!\n");
				printf("이런, 내 소개가 늦었군. 나는 복싱 코치라네.\n");
				printf("자네 나랑 세계를 제패해볼 생각 없는가? 자네라면 분명히 할 수 있다고 믿네.\n");
				printf("생각이 있다면 여기로 와주게.\n");
				printf("==============복싱센터가 오픈되었습니다!(번화가에서 입장가능)==============\n\n");
				printf("아무 버튼이나 입력하면 게임을 진행합니다.\n");
				coach_met++;
				scanf_s("%d", &choice);
				printf("\n");
				locate(current);
				stat(player);
			}
			printf("1.벤치에 앉기.- 체력을 5 회복합니다. 하루에 한 번 가능.\n");
			printf("2.거리로 이동하기.\n");
			scanf_s("%d", &choice);
			printf("\n");

			if (choice == 1) {
				if (bench != player.day)
				{
					player.hp += 5;
					bench = player.day;
					printf("벤치에 앉아서 조금 쉬었습니다.\n");
				}
				else
				{
					printf("이미 벤치에서 쉬었습니다.\n");
				}
				
			}
			else if (choice == 2) {
				current = street;
				}
			
			else
			{
				printf("잘못된 입력입니다.\n");
			}
		}
		else if (current == burnart) {
			printf("1.거리로 이동하기.\n");
			printf("2.학원으로 이동하기.(지력 50 이상 입장가능.)\n");
			printf("3.헬스장으로 이동하기.(근력 50 이상 입장가능.)\n");
			printf("4.산업단지로 이동하기.\n");
			if (coach_met == 1)
			{
				printf("5.복싱 센터로 이동하기.\n");
			}
			scanf_s("%d", &choice);
			printf("\n");
			if (choice == 1) {
				current = street;
			}
			else if (choice == 2) {
				if (player.intel < 50) {
					printf("지력이 부족하여 입구컷 당했습니다..\n");
				}
				else {
					current = arcademy;
				}

			}
			else if (choice == 3) {
				if (player.str < 50) {
					printf("근력이 부족하여 입구컷 당했습니다..\n");
				}
				else {
					current = gym;
				}
			}
			else if (choice == 4) {
				current = inducom;
			}
			else if ((choice == 5) && (coach_met == 1)) {
				current = boxcen;
			}
			else
			{
				printf("잘못된 입력입니다.\n");
			}

			//진행현황-집,거리,편의점 구현완료
			//공원,번화가,학원 장소만 구현
			//나머지 미구현
		}
		else if (current == arcademy) {
			printf("1.집\n");
			printf("2.편의점\n");
			printf("3.공원\n");
			printf("4.번화가\n");
			scanf_s("%d", &choice);
			printf("\n");

			if (choice == 1) {
				current = home;
			}
			else if (choice == 2) {
				current = conv;
			}
			else if (choice == 3) {
				current = park;
			}
			else if (choice == 4) {
				current = burnart;
			}
			else
			{
				printf("잘못된 입력입니다.\n");
			}

			}
	}
	return 0;
}
