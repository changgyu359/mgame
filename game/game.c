#include <stdio.h>

enum Location
{
	home,
	street,
	conv,
	park,
	burnart,
	arcademy
};

struct Data
{

	int hp;
	int str;
	int intel;
	int money;
};

void stat(struct Data data)
{
	printf("체력:%d 근력:%d 지력:%d 돈:%d\n", data.hp, data.str, data.intel, data.money);
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
		.str = 0,
		.intel = 0,
		.money = 1000
	};

	stat(player);
}
