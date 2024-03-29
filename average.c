
void calculateAverages(int marks[][5][2], double averages[][5]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 5; j++) {
            averages[i][j] = (marks[i][j][0] + marks[i][j][1]) / 2.0;
        }
    }
}