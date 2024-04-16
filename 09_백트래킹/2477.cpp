#include <iostream>

using namespace std;

pair<int, int> li[12]; //// 변의 방향과 길이 저장하는 페어 리스트, li

int findArea() { // 육각형 모양의 영역 너비를 구하는 함수
    int big_square; //// 전체 사각형의 넓이
    int small_square; //// 작은 사각형의 넓이
    for (int i = 0; i < 9; i++) {
        if (li[i].first == li[i + 2].first && li[i + 1].first == li[i + 3].first) { // 같은 방향이 한 칸을 건너뛰고 나타나는 형태이면
            big_square = (li[i].second + li[i + 2].second) * (li[i + 1].second + li[i + 3].second); // 전체 사각형 갱신
            small_square = li[i + 2].second * li[i + 1].second; // 작은 사각형(영역이 없는 구역 갱신)
        }
    }
    return big_square - small_square;  //// 전체 사각형 - 작은 사각형으로 반환
}

int main() {
    int k; //// 참외의 개수 k
    cin >> k; //// k 입력

    int direction, length; //// 변의 방향과 길이
    for (int i = 0; i < 6; i++) {
        cin >> direction >> length; //// direction, length 입력
        li[i] = {direction, length}; //// li 방향과 길이 묶어서 저장
    }

    for (int i = 0; i < 6; i++) { //어디서부터 입력이 들어오는지 모르기 때문에 6개 변을 추가해줌
        li[i + 6] = li[i]; //// 참외밭이 육각형이므로 6개의 변을 추가
    }

    int area = findArea(); //// 넓이 구하는 함수의 결과를 area에 저장
    cout << k * area << "\n"; //// 참외 개수만큼 넓이 곱해 반환
    
    return 0;
}