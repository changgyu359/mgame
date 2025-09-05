#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 6000
#define LINES 8
#define LENGTH 256

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
void date(struct Data data)
{
	printf(" 날짜:%d\n", data.day);
	if (data.day % 7 == 6) {
		printf("!!내일은 집세 지불 날입니다!!\n");
	}
}

void stat(struct Data data)
{
	printf("===============스탯===============\n");
	printf("       체력:%d     근력:%d \n", data.hp, data.str);
	printf("       지력:%d     돈:%d \n", data.intel, data.money);
	printf("==================================\n");


}

void output(const char* filename)
{
	FILE* file = fopen(filename, "r");

	char* buffer = malloc(SIZE);

	if (buffer) {
		memset(buffer, 0, SIZE); // 메모리 0으로 초기화
	}

	fread(buffer, 1, SIZE, file);

	printf("%s\n", buffer);

	fclose(file);

	free(buffer);

	
}



void locate(enum Location loc)
{
	switch (loc) {
	case home:output("home.TXT");
		printf("장소 - 집");
		break;
	case street:output("street.TXT");
		printf("장소 - 거리");
		break;
	case conv:output("conv.TXT");
		printf("장소 - 편의점");
		break;
	case park:output("park.txt");
		printf("장소 - 공원");
		break;
	case burnart:output("burnart.TXT");
		printf("장소 - 대로변");
		break;
	case arcademy:output("arcademy.txt");
		printf("장소 - 학원");
		break;
	case gym:output("gym.TXT");
		printf("장소 - 헬스장");
		break;
	case inducom:output("inducom.TXT");
		printf("장소 - 산업단지");
		break;
	case boxcen:output("boxcen.TXT");
		printf("장소 - 복싱 센터");
		break;
	case research:output("research.txt");
		printf("장소 - 연구소");
		break;
	case food: output("food.txt");
		printf("장소 - 음식점");
		break;
	}
	printf(" /");
}

int main()
{
	struct Data player =
	{
		.hp = 100,
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

	char message[LINES][LENGTH] = { 0, };

	output("TITLE.TXT");
	printf("1.바로 게임 시작하기.\n");
	printf("2.게임 설명 듣기.\n");
	scanf_s("%d", &choice);
	if (choice == 1) {
		system("cls");
	}
	else if (choice == 2) {
		printf("이 게임은 자신의 캐릭터를 키우면 되는 간단한 게임입니다.\n");
		printf("캐릭터의 근력,지력을 올려 캐릭터를 키우고 더 높은 목표를 향해 나아가세요.\n");
		printf("단, 주의할 점이 두 가지 있습니다.\n");
		printf("1.체력이 0이되면 게임오버입니다.\n");
		printf("2.7일마다 집세를 5000원 걷습니다. 집세를 내지 못하면 게임오버입니다.\n");
		printf("엔딩은 총 3가지가 있으니 재밌게 즐겨주시길 바랍니다.\n");
		printf("*숫자 외에 다른 키를 입력하지 마세요.\n");
		printf("준비가 되셨으면 아무키나 입력해주세요.\n");
		scanf_s("%d", &choice);
		
	}
	while (1) {
		system("cls");
		if (player.hp <= 0) {
			output("death1.TXT");
			printf("체력이 없어서 사망했습니다. 게임오버.\n");
			break;
		}
		if (player.day % 7 != 0) {
			day7 = 1;
		}
		if ((player.day % 7 == 0) & (day7 == 1)) {
			if (player.money < 5000) {
				output("death2.TXT");
				printf("집세를 낼 돈이 부족하여 쫓겨났습니다. 게임오버.\n");
				break;
			}
			else {
				player.money -= 5000;
				day7 = 0;
				output("zibul.TXT");
				printf("집세 지불 날입니다. 집세 5000원을 지불합니다.\n");
				printf("계속 진행하려면 아무 글자나 입력해주세요.\n");
				scanf_s("%d", &choice);
				system("cls");;
			}
		}
		if (boxcon == 5)
		{
			output("end1.TXT");
			printf("당신은 복싱 세계대회에서 우승했습니다.\n");
			printf("축하합니다! 엔딩에 도달했습니다.\n");
			printf("엔딩1:복싱 세계대회 우승자\n");
			break;
		}

		if (player.money == 3000000)
		{
			output("end2.TXT");
			printf("당신은 엄청난 돈을 벌어 백만장자가 되었습니다.\n");
			printf("축하합니다! 엔딩에 도달했습니다.\n");
			printf("엔딩2:백만장자\n");
			break;

		}
		if (endrun == 20)
		{
			output("end3.TXT");
			printf("당신의 연구는 성공하여 노벨상을 수상하였습니다.\n");
			printf("축하합니다! 엔딩에 도달했습니다.\n");
			printf("엔딩3:노벨상 수상자\n");
			break;
		}
		if (player.day == 365 && end4 == 0) {
			printf("당신은 이 게임에서 벌써 1년을 보냈습니다.\n"); 
			printf("이 곳에서의 생활은 마음에 드시나요?\n");
			printf("히든 업적:게임에서의 1년.\n");
			printf("계속 진행하려면 아무 글자나 입력해주세요.\n");
			end4++;
			scanf_s("%d", &choice);
			system("cls");
		}

		locate(current);
		date(player);
		printf("----------------------------------\n");
		
		for (int i = 0; i < LINES; i++) {
			if (message[i][0] != '\0') {
				printf(" %s\n", message[i]);
			}
		}
		printf("----------------------------------\n");
		stat(player);

		
		memset(message, 0, sizeof(message));

		if (current == home) {
			printf("1.잠자기-체력을 20회복하고 하루가 지납니다.\n");
			printf("2.공부하기-지력이 2증가하고 체력이 5감소합니다.\n");
			printf("3.운동하기-근력이 2증가하고 체력이 7감소합니다.\n");
			printf("4.거리로 나가기.\n");
			scanf_s("%d", &choice);

			if (choice == 1) {
				player.hp += 20;
				player.day += 1;
				snprintf(message[0], LENGTH, "잠을 자서 체력을 %d 회복했습니다.", 20);
				snprintf(message[1], LENGTH, "하루가 지났습니다.");
			}
			else if (choice == 2) {
				player.hp -= 5;
				player.intel += 2;
				snprintf(message[0], LENGTH, "공부를 하여 지력이 %d 상승하였습니다.", 2);
			}
			else if (choice == 3) {
				player.hp -= 7;
				player.str += 2;
				snprintf(message[0], LENGTH, "운동을 하여 근력이 %d 상승하였습니다.", 2);
			}
			else if (choice == 4) {
				current = street;
				snprintf(message[0], LENGTH, "거리로 나갑니다.");
			}
			else if (choice == 365) {
				player.hp += 10000;
				player.str += 10000;
				player.intel += 10000;
				player.money += 10000;
				snprintf(message[0], LENGTH, "치트키 발동!");
			}
			else

			{
				snprintf(message[0], LENGTH, "잘못된 입력입니다.");
			}
		}
		else if (current == street) {
			printf("1.집에 돌아가기\n");
			printf("2.편의점으로 이동하기\n");
			printf("3.공원으로 이동하기\n");
			printf("4.대로변으로 이동하기\n");
			scanf_s("%d", &choice);

			if (choice == 1) {
				current = home;
				snprintf(message[0], LENGTH, "집으로 돌아갑니다.");
			}
			else if (choice == 2) {
				current = conv;
				snprintf(message[0], LENGTH, "편의점 알바:어서오세요.");
			}
			else if (choice == 3) {
				current = park;
				snprintf(message[0], LENGTH, "공원으로 이동합니다.");
			}
			else if (choice == 4) {
				current = burnart;
				snprintf(message[0], LENGTH, "대로변으로 이동합니다.");
			}
			else
			{
				snprintf(message[0], LENGTH, "잘못된 입력입니다.");
			}
		}
		else if (current == conv) {
			printf("1.삼각김밥-체력 10회복,1000원\n");
			printf("2.음료수-체력 5회복,500원\n");
			printf("3.알바하기-체력을 10소모하여 2000원을 법니다. 하루가 지납니다.\n");
			printf("4.거리로 나가기.\n");
			scanf_s("%d", &choice);

			if (choice == 1) {
				if (player.money < 1000) {
					snprintf(message[0], LENGTH, "돈이 부족합니다.");
				}
				else {
					player.money -= 1000;
					player.hp += 10;
					snprintf(message[0], LENGTH, "삼각김밥을 먹어 체력을 10 회복했습니다.");
				}

			}
			else if (choice == 2) {
				if (player.money < 500) {
					snprintf(message[0], LENGTH, "돈이 부족합니다.");
				}
				else {
					player.money -= 500;
					player.hp += 50;
					snprintf(message[0], LENGTH, "음료수를 마셔 체력을 50 회복했습니다.");
				}

			}
			else if (choice == 3) {
				player.hp -= 10;
				player.money += 2000;
				player.day++;
				snprintf(message[0], LENGTH, "편의점에서 알바를 했습니다.");
				snprintf(message[1], LENGTH, "하루가 지났습니다.");
			}
			else if (choice == 4) {
				current = street;
				snprintf(message[0], LENGTH, "거리로 나갑니다.");
			}
			else
			{
				snprintf(message[0], LENGTH, "잘못된 입력입니다.");
			}
		}
		else if (current == park) {
			if ((player.str >= 400) && (coach_met == 0)) {
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
				date(player);
				stat(player);
			}
			printf("1.벤치에 앉기.- 체력을 10 회복합니다. 하루에 한 번 가능.\n");
			printf("2.거리로 이동하기.\n");
			scanf_s("%d", &choice);

			if (choice == 1) {
				if (bench != player.day)
				{
					player.hp += 10;
					bench = player.day;
					snprintf(message[0], LENGTH, "벤치에 앉아서 조금 쉬었습니다.");
				}
				else
				{
					snprintf(message[0], LENGTH, "이미 벤치에서 쉬었습니다.");
				}

			}
			else if (choice == 2) {
				current = street;
				snprintf(message[0], LENGTH, "거리로 나갑니다.");
			}
			else
			{
				snprintf(message[0], LENGTH, "잘못된 입력입니다.");
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

			if (choice == 1) {
				current = street;
				snprintf(message[0], LENGTH, "거리로 나갑니다.");
			}
			else if (choice == 2) {
				if (player.intel < 50) {
					snprintf(message[0], LENGTH, "지력이 부족하여 입구컷 당했습니다..");
				}
				else {
					current = arcademy;
					snprintf(message[0], LENGTH, "학원으로 이동합니다.");
				}

			}
			else if (choice == 3) {
				if (player.str < 50) {
					snprintf(message[0], LENGTH, "근력이 부족하여 입구컷 당했습니다..");
				}
				else {
					current = gym;
					snprintf(message[0], LENGTH, "헬스장으로 이동합니다.");
				}
			}
			else if (choice == 4) {
				current = inducom;
				snprintf(message[0], LENGTH, "산업단지로 이동합니다.");
			}
			else if (choice == 5) {
				current = food;
				snprintf(message[0], LENGTH, "종업원:어서오세요!");
			}
			else if ((choice == 6) && (coach_met == 1)) {
				current = boxcen;
				snprintf(message[0], LENGTH, "복싱 센터로 이동합니다.");
			}
			else
			{
				snprintf(message[0], LENGTH, "잘못된 입력입니다.");
			}
		}
		else if (current == arcademy) {
			printf("1.학원 하급반-체력을 10소모하여 지력을 5증가시킵니다.\n");
			printf("2.학원 상급반-지력 100이상, 체력을 10소모하여 지력을 10증가시킵니다. 하루가 지납니다.\n");
			printf("3.학원 알바-체력을 10소모하여 4000원을 법니다. 하루가 지납니다.\n");
			printf("4.대로변으로 나가기.\n");
			scanf_s("%d", &choice);

			if (choice == 1) {
				player.intel += 5;
				player.hp -= 10;
				snprintf(message[0], LENGTH, "공부를 하여 지력이 5 상승했습니다.");
			}
			else if (choice == 2) {
				if (player.intel < 100)
				{
					snprintf(message[0], LENGTH, "지력이 부족합니다.");
				}
				else
				{
					player.intel += 10;
					player.hp -= 10;
					player.day++;
					snprintf(message[0], LENGTH, "공부를 하여 지력이 10 상승했습니다.");
					snprintf(message[1], LENGTH, "하루가 지났습니다.");
				}

			}
			else if (choice == 3) {
					player.money += 4000;
					player.hp -= 10;
					player.day++;
					snprintf(message[0], LENGTH, "학원 알바를 하여 돈을 4000원 벌었습니다.");
					snprintf(message[1], LENGTH, "하루가 지났습니다.");
				
			}
			else if (choice == 4) {
				current = burnart;
				snprintf(message[0], LENGTH, "대로변으로 나갑니다.");
			}
			else
			{
				snprintf(message[0], LENGTH, "잘못된 입력입니다.");
			}
		}
		else if (current == gym) {
			printf("1.아령 들기-체력을 10 소모하여 근력을 4 증가시킵니다.\n");
			printf("2.스쿼트 하기-근력 100이상, 체력을 20소모하여 근력을 10 증가시킵니다.\n");
			printf("3.데드 리프트-근력 200이상, 체력을 30소모하여 근력을 20 증가시킵니다.\n");
			printf("4.대로변으로 나가기.\n");
			scanf_s("%d", &choice);

			if (choice == 1) {
				player.hp -= 10;
				player.str += 4;
				snprintf(message[0], LENGTH, "운동을 하여 근력이 4 상승했습니다.");
			}
			else if (choice == 2) {
				if (player.str < 100)
				{
					snprintf(message[0], LENGTH, "근력이 부족합니다.");
				}
				else
				{
					player.hp -= 20;
					player.str += 10;
					snprintf(message[0], LENGTH, "운동을 하여 근력이 10 상승했습니다.");
				}
			}
			else if (choice == 3) {
				if (player.str < 200)
				{
					snprintf(message[0], LENGTH, "근력이 부족합니다.");
				}
				else
				{
					player.hp -= 30;
					player.str += 20;
					snprintf(message[0], LENGTH, "운동을 하여 근력이 20 상승했습니다.");
				}
			}
			else if (choice == 4) {
				current = burnart;
				snprintf(message[0], LENGTH, "대로변으로 나갑니다.");
			}
			else
			{
				snprintf(message[0], LENGTH, "잘못된 입력입니다.");
			}
		}
		else if (current == food) {
			printf("1.제육덮밥 주문하기-체력 60회복,5000원\n");
			printf("2.모둠 돈가스 주문하기-체력 130회복,10000원\n");
			printf("3.LA갈비 주문하기-체력 300회복,20000원\n");
			printf("4.대로변으로 나가기.\n");
			scanf_s("%d", &choice);

			if (choice == 1) {
				if (player.money < 5000) {
					snprintf(message[0], LENGTH, "돈이 부족합니다.");
				}
				else {
					player.money -= 5000;
					player.hp += 60;
					snprintf(message[0], LENGTH, "제육덮밥을 먹어 체력을 60 회복했습니다.");
				}

			}
			else if (choice == 2) {
				if (player.money < 10000) {
					snprintf(message[0], LENGTH, "돈이 부족합니다.");
				}
				else {
					player.money -= 10000;
					player.hp += 130;
					snprintf(message[0], LENGTH, "돈가스를 먹어 체력을 130 회복했습니다.");
				}

			}
			else if (choice == 3) {
				if (player.money < 20000) {
					snprintf(message[0], LENGTH, "돈이 부족합니다.");
				}
				else {
					player.money -= 20000;
					player.hp += 300;
					snprintf(message[0], LENGTH, "LA갈비를 먹어 체력을 300 회복했습니다.");
				}

			}
			else if (choice == 4) {
				current = burnart;
				snprintf(message[0], LENGTH, "대로변으로 나갑니다.");
			}
			else
			{
				snprintf(message[0], LENGTH, "잘못된 입력입니다.");
			}
		}
		else if (current == inducom) {
			printf("1.부품 제작 알바-근력50,지력50이상, 체력을 20소모하여 6000원을 법니다. 하루가 지납니다.\n");
			printf("2.상하차 알바-근력 200이상, 체력을 50소모하여 20000원을 법니다. 하루가 지납니다.\n");
			printf("3.연구소로 이동하기(지력 500이상 입장가능).\n");
			printf("4.대로변으로 이동하기.\n");
			scanf_s("%d", &choice);

			if (choice == 1) {
				if (player.str < 50 || player.intel < 50)
				{
					snprintf(message[0], LENGTH, "근력이나 지력이 부족합니다.");
				}
				else
				{
					player.day++;
					player.hp -= 20;
					player.money += 6000;
					snprintf(message[0], LENGTH, "일을 하여 돈을 6000원 벌었습니다.");
					snprintf(message[1], LENGTH, "하루가 지났습니다.");
				}

			}
			else if (choice == 2) {
				if (player.str < 200)
				{
					snprintf(message[0], LENGTH, "근력이 부족합니다.");
				}
				else
				{
					player.day++;
					player.hp -= 50;
					player.money += 20000;
					snprintf(message[0], LENGTH, "일을 하여 돈을 20000원 벌었습니다.");
					snprintf(message[1], LENGTH, "하루가 지났습니다.");
				}
			}
			else if (choice == 3) {
				if (player.intel < 500)
				{
					snprintf(message[0], LENGTH, "지력이 부족합니다.");
				}
				else
				{
					current = research;
					snprintf(message[0], LENGTH, "연구소로 이동합니다.");
				}
			}
			else if (choice == 4) {
				current = burnart;
				snprintf(message[0], LENGTH, "대로변으로 이동합니다.");
			}
			else
			{
				snprintf(message[0], LENGTH, "잘못된 입력입니다.");
			}
		}
		else if (current == research) {
			printf("1.돈이 되는 연구하기-체력을 30 소모하여 진행도를 올립니다. 하루가 지납니다. 진행도를 4까지 달성하면 60000원을 얻습니다. / 현재 진행도 : % d\n", monrun);
			printf("2.노벨상을 탈 연구하기-체력을 100소모하여 진행도를 올립니다. 하루가 지납니다. 진행도를 20까지 올리면.../ 현재 진행도:%d\n", endrun);
			printf("3.산업단지로 이동하기.\n");
			scanf_s("%d", &choice);

			if (choice == 1) {
				player.hp -= 30;
				player.day++;
				if (monrun < 3)
				{
					snprintf(message[0], LENGTH, "돈이 되는 연구를 했습니다.");
					snprintf(message[1], LENGTH, "현재 진행도: %d", monrun + 1);
					snprintf(message[2], LENGTH, "하루가 지났습니다.");
					monrun++;
				}
				else
				{
					snprintf(message[0], LENGTH, "연구 성과로 돈을 60000원 벌었습니다.");
					snprintf(message[1], LENGTH, "하루가 지났습니다.");
					monrun = 0;
					player.money += 60000;
				}

			}
			else if (choice == 2) {
				snprintf(message[0], LENGTH, "노벨상을 탈 연구를 했습니다.");
				snprintf(message[1], LENGTH, "현재 진행도: %d", endrun + 1);
				snprintf(message[2], LENGTH, "하루가 지났습니다.");
				player.day++;
				player.hp -= 100;
				endrun++;
			}
			else if (choice == 3) {
				current = inducom;
				snprintf(message[0], LENGTH, "산업단지로 이동합니다.");
			}
			else
			{
				snprintf(message[0], LENGTH, "잘못된 입력입니다.");
			}
		}
		else if (current == boxcen) {


			printf("1.코치와 대화하기\n");
			printf("2.대로변으로 이동하기.\n");
			scanf_s("%d", &choice);

			if (choice == 1) {
				printf("필요한게 있는가?\n");
				printf("1.대회에 대해 알려주세요.\n");
				printf("2.훈련을 하고싶어요-체력을 70소모하여 근력을 증가시킵니다.\n");
				printf("3.대회에 참가하고 싶어요.\n");
				scanf_s("%d", &choice);

				if (choice == 1) {
					snprintf(message[0], LENGTH, "그래, 세계 복싱대회에 대해 알려주지.");
					snprintf(message[1], LENGTH, "세계 복싱대회에 참가하려면 4번 경기에 참가해야 하네.");
					snprintf(message[2], LENGTH, "각 경기에서 이기면 다음 경기로 넘어가는 식이지.");
					snprintf(message[3], LENGTH, "졌다고 해서 너무 상심하지 말게. 그 경기부터 다시 할 수 있으니.");
					snprintf(message[4], LENGTH, "다만 경기에서 질 경우 조금 심한 부상을 입을테니 막무가내로 시도하지는 말게나.");
					snprintf(message[5], LENGTH, "경기에서 믿을 건 자네, 특히 자네의 근력일세.");
					snprintf(message[6], LENGTH, "자네의 그 근력으로 세계를 제패해보게나!");
					snprintf(message[7], LENGTH, "아 그리고 대회 결과에 상관없이 날짜가 진행되니 그것도 잊지 말고.");
				}
				else if (choice == 2) {
					player.hp -= 70;
					player.str += 70;
					snprintf(message[0], LENGTH, "훈련을 하여 근력이 70 상승했습니다.");
				}
				else if (choice == 3) {
					system("cls");
					output("vs.TXT");
					printf("%d번째 경기를 시작합니다.", boxcon);
					printf("계속 진행하려면 아무 글자나 입력해주세요.\n");
					scanf_s("%d", &choice);

					if (boxcon == 1) {
						if (player.str < 500) {
							system("cls");
							output("defeat.TXT");
							printf("경기에서 패배했습니다...\n");
							printf("체력이 1이 되었습니다.\n");
							player.hp = 1;
							printf("계속 진행하려면 아무 글자나 입력해주세요.\n");
							scanf_s("%d", &choice);
						}
						else {
							system("cls");
							output("win.TXT");
							printf("첫번째 경기에서 승리했습니다!\n");
							boxcon++;
							printf("상금으로 20000원을 획득했습니다.\n");
							player.money += 20000;
							printf("계속 진행하려면 아무 글자나 입력해주세요.\n");
							scanf_s("%d", &choice);
						}

					}
					else if (boxcon == 2) {
						if (player.str < 700) {
							system("cls");
							output("defeat.TXT");
							printf("경기에서 패배했습니다...\n");
							printf("체력이 1이 되었습니다.\n");
							player.hp = 1;
							printf("계속 진행하려면 아무 글자나 입력해주세요.\n");
							scanf_s("%d", &choice);
						}
						else {
							system("cls");
							output("win.TXT");
							printf("두번째 경기에서 승리했습니다!\n");
							boxcon++;
							printf("상금으로 50000원을 획득했습니다.\n");
							player.money += 50000;
							printf("계속 진행하려면 아무 글자나 입력해주세요.\n");
							scanf_s("%d", &choice);
						}

					}
					else if (boxcon == 3) {
						if (player.str < 1000) {
							system("cls");
							output("defeat.TXT");
							printf("경기에서 패배했습니다...\n");
							printf("체력이 1이 되었습니다.\n");
							player.hp = 1;
							printf("계속 진행하려면 아무 글자나 입력해주세요.\n");
							scanf_s("%d", &choice);
						}
						else {
							system("cls");
							output("win.TXT");
							printf("세번째 경기에서 승리했습니다!\n");
							boxcon++;
							printf("상금으로 100000원을 획득했습니다.\n");
							player.money += 100000;
							printf("계속 진행하려면 아무 글자나 입력해주세요.\n");
							scanf_s("%d", &choice);
						}

					}
					else if (boxcon == 4) {
						if (player.str < 1200) {
							system("cls");
							output("defeat.TXT");
							printf("경기에서 패배했습니다...\n");
							printf("체력이 1이 되었습니다.\n");
							player.hp = 1;
							printf("계속 진행하려면 아무 글자나 입력해주세요.\n");
							scanf_s("%d", &choice);
						}
						else {
							system("cls");
							output("win.TXT");
							printf("최종 경기에서 승리했습니다!\n");
							boxcon++;
							printf("계속 진행하려면 아무 글자나 입력해주세요.\n");
							scanf_s("%d", &choice);
						}

					}
					player.day++;
				}
				else
				{
					snprintf(message[0], LENGTH, "잘못된 입력입니다.");
				}
			}
			else if (choice == 2) {
				current = burnart;
				snprintf(message[0], LENGTH, "대로변으로 나갑니다.");
			}
			else
			{
				snprintf(message[0], LENGTH, "잘못된 입력입니다.");
			}
		}

		
	}
	return 0;
}

