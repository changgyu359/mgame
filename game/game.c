#include <stdio.h>
#include<stdlib.h>

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
	research,
	boxcen,
	food
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
	case burnart: printf("장소 - 대로변");
		break;
	case arcademy: printf("장소 - 학원");
		break;
	case gym: printf("장소 - 헬스장");
		break;
	case inducom: printf("장소 - 산업단지");
		break;
	case boxcen: printf("장소 - 복싱 센터");
		break;
	}
	printf(" /");
}





int main()
{
	struct Data player =
	{
		.hp = 10,
		.str = 0,
		.intel = 0,
		.money = 1000,
		.day = 1
	};
	enum Location current = home;
	int choice = 0;
	int coach_met = 0;
	int day7 = 0;
	int bench = 0;
	int monrun = 0;
	int endrun = 0;
	int boxcon = 1;
	int end4 = 0;
	int boxcoach = 0;

	FILE* title = fopen("TITLE.TXT", "r");

	char buffer[5000] = { 0, };
	fread(buffer, 1, 5000, title);
	printf("%s", buffer);
	fclose(title);
	printf("1.바로 게임 시작하기.\n");
	printf("2.게임 설명 듣기.\n");
	scanf_s("%d", &choice);
	if (choice == 1) {
		system("cls");
	}
	else if (choice == 2) {
		printf("이 게임은 자신의 캐릭터를 키우면 되는 간단한 게임입니다.\n");
		printf("캐릭터의 근력,지력을 올려 캐릭터를 키우고 더 높은 목표를 향해 나아가세요.\n");
		printf("단, 주의할 점이 두 가지 있습니다 .\n");
		printf("1.체력이 0이되면 게임오버입니다 .\n");
		printf("2.7일마다 집세를 10000원 걷습니다. 집세를 내지 못하면 게임오버입니다.\n");
		printf("엔딩은 총 3가지가 있으니 재밌게 즐겨주시길 바랍니다.\n");
		printf("준비가 되셨으면 아무키나 입력해주세요.\n");
		scanf_s("%d", &choice);
		system("cls");
	}
	while (1) {
				if (player.hp <= 0) {
			printf("체력이 없어서 사망했습니다. 게임오버.\n");
			break;
		}
		if (player.day % 7 != 0) {
			day7 = 1;
		}
		if ((player.day % 7 == 0) & (day7 == 1)) {
			if (player.money < 1000) {
				printf("집세를 낼 돈이 부족하여 쫓겨났습니다. 게임오버.\n");
				break;
			}
			else {
				player.money -= 10000;
				day7 = 0;
				printf("집세 지불 날입니다. 집세 10000원을 지불합니다.\n");
			}
		}
		if (boxcon == 5)
		{
			printf("당신은 복싱 세계대회에서 우승했습니다.\n");
			printf("축하합니다! 엔딩에 도달했습니다.\n");
			printf("엔딩1:복싱 세계대회 우승자\n");
			break;
		}

		if (player.money == 1000000)
		{
			printf("당신은 엄청난 돈을 벌어 백만장자가 되었습니다.\n");
			printf("축하합니다! 엔딩에 도달했습니다.\n");
			printf("엔딩2:백만장자\n");
			break;

		}
		if (endrun == 20)
		{
			printf("당신의 연구는 성공하여 노벨상을 수상하였습니다.\n");
			printf("축하합니다! 엔딩에 도달했습니다.\n");
			printf("엔딩3:노벨상 수상자\n");
			break;
		}
		if (player.day == 365 && end4 == 0) {
			printf("당신은 이 게임에서 벌써 1년을 보냈습니다.\n"); \
				printf("이 곳에서의 생활은 마음에 드시나요?\n");
			printf("히든 업적:게임에서의 1년.\n");
			printf("계속 진행하려면 아무 글자나 입력해주세요.\n");
			end4++;
			scanf_s("%d", &choice);
			system("cls");
		}
		locate(current);
		stat(player);
		if (current == home) {
			printf("1.잠자기-체력을 20회복하고 시간을 진행시킵니다.\n");
			printf("2.공부하기-지력이 2증가하고 체력이 5감소합니다.\n");
			printf("3.운동하기-근력이 2증가하고 체력이 7감소합니다.\n");
			printf("4.거리로 나가기.\n");
			scanf_s("%d", &choice);
			system("cls");
			if (choice == 1) {
				player.hp += 20;
				player.day += 1;
				printf("잠을 자서 체력을 회복했습니다.\n");
				printf("하루가 지났습니다.\n");
			}
			else if (choice == 2) {
				player.hp -= 5;
				player.intel += 2;
				printf("공부를 하여 지력이 상승하였습니다.\n");
			}
			else if (choice == 3) {
				player.hp -= 7;
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
			printf("1.집에 돌아가기\n");
			printf("2.편의점으로 이동하기\n");
			printf("3.공원으로 이동하기\n");
			printf("4.대로변으로 이동하기\n");
			scanf_s("%d", &choice);
			system("cls");

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
			printf("3.알바하기-체력을 10소모하여 2000원을 법니다. 시간이 진행됩니다.\n");
			printf("4.거리로 나가기.\n");
			scanf_s("%d", &choice);
			system("cls");

			if (choice == 1) {
				if (player.money < 1000) {
					printf("돈이 부족합니다.\n");
				}
				else {
					player.money -= 1000;
					player.hp += 10;
					printf("삼각김밥을 먹어 체력을 회복했습니다.\n");
				}

			}
			else if (choice == 2) {
				if (player.money < 500) {
					printf("돈이 부족합니다.\n");
				}
				else {
					player.money -= 500;
					player.hp += 50;
					printf("음료수를 마셔 체력을 회복했습니다.\n");
				}

			}
			else if (choice == 3) {
				player.hp -= 10;
				player.money += 2000;
				player.day++;
				printf("편의점에서 알바를 했습니다.\n");
				printf("하루가 지났습니다.\n");
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

			if ((player.str >= 200) && (coach_met == 0)) {
				printf("=================공원을 걷던 당신에게 누군가 다가왔습니다.=================\n");
				printf("자네 몸이 아주 좋군, 아주 훌륭한 원석이야!\n");
				printf("이런, 내 소개가 늦었군. 나는 복싱 코치라네.\n");
				printf("자네 나랑 세계를 제패해볼 생각 없는가? 자네라면 분명히 할 수 있다고 믿네.\n");
				printf("생각이 있다면 여기로 와주게.\n");
				printf("==============복싱 센터가 오픈되었습니다!(대로변에서 입장가능)=============\n\n");
				printf("계속 진행하려면 아무 글자나 입력해주세요.\n");
				coach_met++;
				scanf_s("%d", &choice);
				system("cls");;
				locate(current);
				stat(player);
			}
			printf("1.벤치에 앉기.- 체력을 5 회복합니다. 하루에 한 번 가능.\n");
			printf("2.거리로 이동하기.\n");
			scanf_s("%d", &choice);
			system("cls");

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
			printf("5.음식점으로 이동하기.\n");
			if (coach_met == 1)
			{
				printf("6.복싱 센터로 이동하기.\n");
			}
			scanf_s("%d", &choice);
			system("cls");
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
			else if (choice == 5) {
				current = food;
			}
			else if ((choice == 6) && (coach_met == 1)) {
				current = boxcen;
			}
			else
			{
				printf("잘못된 입력입니다.\n");
			}


		}
		else if (current == arcademy) {
			printf("1.학원 하급반-체력을 소모하여 지력을 증가시킵니다.\n");
			printf("2.학원 상급반-지력 100이상, 체력을 소모하여 지력을 증가시킵니다. 시간이 진행됩니다.\n");
			printf("3.학원 알바-지력 200필요, 체력을 소모하여 돈을 법니다. 시간이 진행됩니다.\n");
			printf("4.대로변으로 나가기.\n");
			scanf_s("%d", &choice);
			system("cls");

			if (choice == 1) {
				player.intel += 5;
				player.hp -= 10;
				printf("공부를 하여 지력이 상승했습니다.");

			}
			else if (choice == 2) {
				if (player.intel < 100)
				{
					printf("지력이 부족합니다.\n");
				}
				else
				{
					player.intel += 10;
					player.hp -= 10;
					player.day++;
					printf("공부를 하여 지력이 상승했습니다.\n");
					printf("하루가 지났습니다.\n");
				}

			}
			else if (choice == 3) {
				if (player.intel < 200)
				{
					printf("지력이 부족합니다.\n");
				}
				else
				{
					player.money += 5000;
					player.hp -= 10;
					player.day++;
					printf("학원 알바를 하여 돈을 벌었습니다.\n");
					printf("하루가 지났습니다.\n");
				}
			}
			else if (choice == 4) {
				current = burnart;
			}
			else
			{
				printf("잘못된 입력입니다.\n");
			}

		}
		else if (current == gym) {
			printf("1.아령 들기-체력을 소모하여 근력을 증가시킵니다.\n");
			printf("2.스쿼트 하기-근력 100이상, 체력을 소모하여 근력을 10 증가시킵니다.\n");
			printf("3.데드 리프트-근력 200이상, 체력을 소모하여 근력을 20 증가시킵니다.\n");
			printf("4.대로변으로 나가기.\n");
			scanf_s("%d", &choice);
			system("cls");

			if (choice == 1) {
				player.hp -= 10;
				player.str += 4;
				printf("운동을 하여 지력이 상승했습니다.");

			}
			else if (choice == 2) {
				if (player.str < 100)
				{
					printf("근력이 부족합니다.\n");
				}
				else
				{
					player.hp -= 20;
					player.str += 10;
					printf("운동을 하여 근력이 상승했습니다.\n");
				}
			}
			else if (choice == 3) {
				if (player.str < 200)
				{
					printf("근력이 부족합니다.\n");
				}
				else
				{
					player.hp -= 30;
					player.str += 20;
					printf("운동을 하여 근력이 상승했습니다.\n");
				}
			}
			else if (choice == 4) {
				current = burnart;
			}
			else
			{
				printf("잘못된 입력입니다.\n");
			}
		}
		else if (current == food) {
			printf("1.제육덮밥 주문하기-체력 60회복,7000원\n");
			printf("2.모둠 돈가스 주문하기-체력 100회복,13000원\n");
			printf("3.LA갈비 주문하기-체력 200회복,30000원\n");
			printf("4.대로변으로 나가기.\n");
			scanf_s("%d", &choice);
			system("cls");

			if (choice == 1) {
				if (player.money < 7000) {
					printf("돈이 부족합니다.\n");
				}
				else {
					player.money -= 7000;
					player.hp += 60;
					printf("제육덮밥을 먹어 체력을 회복했습니다.\n");
				}

			}
			else if (choice == 2) {
				if (player.money < 13000) {
					printf("돈이 부족합니다.\n");
				}
				else {
					player.money -= 13000;
					player.hp += 100;
					printf("돈가스를 먹어 체력을 회복했습니다.\n");
				}

			}
			else if (choice == 3) {
				if (player.money < 30000) {
					printf("돈이 부족합니다.\n");
				}
				else {
					player.money -= 30000;
					player.hp += 200;
					printf("LA갈비를 먹어 체력을 회복했습니다.\n");
				}

			}
			else if (choice == 4) {
				current = burnart;
			}
			else
			{
				printf("잘못된 입력입니다.\n");
			}
		}
		else if (current == inducom) {
			printf("1.부품 제작 알바-근력50,지력50이상, 체력을 15소모하여 4000원을 법니다.\n");
			printf("2.상하차 알바-근력 200이상, 체력을 50소모하여 10000원을 법니다.\n");
			printf("3.연구소로 이동하기(지력 500이상 입장가능).\n");
			printf("4.대로변으로 이동하기.\n");
			scanf_s("%d", &choice);
			system("cls");

			if (choice == 1) {
				if (player.str < 50 || player.intel < 50)
				{
					printf("근력이나 지력이 부족합니다.\n");
				}
				else
				{
					player.hp -= 15;
					player.money += 4000;
					printf("일을 하여 돈을 벌었습니다.\n");
				}

			}
			else if (choice == 2) {
				if (player.str < 200)
				{
					printf("근력이 부족합니다.\n");
				}
				else
				{
					player.hp -= 50;
					player.money += 10000;
					printf("일을 하여 돈을 벌었습니다.\n");
				}
			}
			else if (choice == 3) {
				if (player.intel < 500)
				{
					printf("지력이 부족합니다.\n");
				}
				else
				{
					current = research;
				}
			}
			else if (choice == 4) {
				current = burnart;
			}
			else
			{
				printf("잘못된 입력입니다.\n");
			}
		}
		else if (current == research) {
			printf("1.돈이 되는 연구하기-체력을 30 소모하여 진행도를 올립니다.\n");
			printf("진행도를 4까지 달성하면 20000원을 얻습니다./ 현재 진행도:%d\n", monrun);
			printf("2.노벨상을 탈 연구하기-체력을 100소모하여 진행도를 올립니다.\n");
			printf("진행도를 20까지 올리면.../ 현재 진행도:%d\n", endrun);
			printf("3.산업단지로 이동하기.\n");
			scanf_s("%d", &choice);
			system("cls");

			if (choice == 1) {
				if (monrun < 3)
				{
					printf("돈이 되는 연구를 했습니다.\n");
					monrun++;
				}
				else
				{
					printf("연구 성과로 돈을 벌었습니다.\n");
					player.money += 20000;
					monrun = 0;
				}

			}
			else if (choice == 2) {

				printf("노벨상을 탈 연구를 했습니다.\n");
				endrun++;
			}
			else if (choice == 3) {
				current = inducom;
			}
			else
			{
				printf("잘못된 입력입니다.\n");
			}
		}
		else if (current == boxcen) {

			printf("1.코치와 대화하기\n");
			printf("2.대로변으로 이동하기.\n");
			scanf_s("%d", &choice);
			system("cls");

			if (choice == 1) {
				printf("필요한게 있는가?\n");
				printf("1.대회에 대해 알려주세요.\n");
				printf("2.훈련을 하고싶어요-체력을 70소모하여 근력을 증가시킵니다.\n");
				printf("3.대회에 참가하고 싶어요.\n");
				scanf_s("%d", &choice);
				system("cls");

				if (choice == 1) {
					printf("그래, 세계 복싱대회에 알려주지.\n");
					printf("세계 복싱대회에 참가하려면 4번 경기에 참가해야하네.\n");
					printf("각 경기에서 이기면 다음 경기로 넘어가는 식이지.\n");
					printf("졌다고 해서 너무 상심하지 말게. 졌다고 처음부터 하는게 아닌 그 경기부터 다시 할 수 있으니.\n");
					printf("다만 경기에서 질 경우 조금 심한 부상을 입을테니 막무가내로 시도하지는 말게나.\n");
					printf("경기에서 믿을 건 자네, 특히 자네의 근력일세.\n");
					printf("자네의 그 근력으로 세계를 제패해보게나!\n");
					printf("계속 진행하려면 아무 글자나 입력해주세요.\n");
					system("cls");
				}
				else if (choice == 2) {
					printf("훈련을 하여 근력이 70 상승했습니다.\n");
					player.hp -= 70;
					player.str += 70;

				}
				else if (choice == 3) {
					printf("%d번째 경기를 시작합니다.\n", boxcon);
					printf("계속 진행하려면 아무 글자나 입력해주세요.\n");
					system("cls");

					if (boxcon == 1) {
						if (player.str < 300) {
							printf("경기에서 패배했습니다...\n");
							printf("체력이 1이 되었습니다.\n");
						}
						else {
							printf("%d번째 경기에서 승리했습니다!\n", boxcon);
							boxcon++;
						}

					}
					if (boxcon == 2) {
						if (player.str < 500) {
							printf("경기에서 패배했습니다...\n");
							printf("체력이 1이 되었습니다.\n");
						}
						else {
							printf("%d번째 경기에서 승리했습니다!\n", boxcon);
							boxcon++;
						}

					}
					if (boxcon == 3) {
						if (player.str < 800) {
							printf("경기에서 패배했습니다...\n");
							printf("체력이 1이 되었습니다.\n");
						}
						else {
							printf("%d번째 경기에서 승리했습니다!\n", boxcon);
							boxcon++;
						}

					}
					if (boxcon == 1) {
						if (player.str < 1200) {
							printf("경기에서 패배했습니다...\n");
							printf("체력이 1이 되었습니다.\n");
						}
						else {
							printf("%d번째 경기에서 승리했습니다!\n", boxcon);
							boxcon++;
						}

					}
				}
				else
				{
					printf("잘못된 입력입니다.\n");
				}
			}
			else if (choice == 2) {

				current = burnart;
			}
			else
			{
				printf("잘못된 입력입니다.\n");
			}
		}
		printf("\n");
	}
		return 0;
	}

