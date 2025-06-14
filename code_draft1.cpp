bool iswinner(const char matrix[3][3])
{
   //checks rows
    for (int i = 0; i < 3; ++i) {
        char first = matrix[i][0];
        if (first != 'e' &&               // ignore empty rows
            matrix[i][1] == first &&
            matrix[i][2] == first)
            return true;
    }

    //checks coloums
    for (int j = 0; j < 3; ++j) {
        char first = matrix[0][j];
        if (first != 'e' &&
            matrix[1][j] == first &&
            matrix[2][j] == first)
            return true;
    }

    //diagonal 
    // main diagonal 0‑0 / 1‑1 / 2‑2
    if (matrix[0][0] != 'e' &&
        matrix[0][0] == matrix[1][1] &&
        matrix[1][1] == matrix[2][2])
        return true;

    // anti‑diagonal 0‑2 / 1‑1 / 2‑0
    if (matrix[0][2] != 'e' &&
        matrix[0][2] == matrix[1][1] &&
        matrix[1][1] == matrix[2][0])
        return true;

    return false;        // no win yet
}



void printBoard(const char m[3][3])
{
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << (m[i][j] == 'e' ? '.' : m[i][j]);
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---------\n";
    }
    cout << "\n\n";
}


int main()
{
    char matrix[3][3] = { {'e','e','e'},
                          {'e','e','e'},
                          {'e','e','e'} };

    int moves = 0;            // total moves made
    char player = 'o';        // 'o' starts (swap if you like)

    while (moves < 9) {
        printBoard(matrix);

        int x, y;
        cout << "Player " << player
             << ", enter row and column (0‑2): ";
        if (!(cin >> x >> y) || x < 0 || x > 2 || y < 0 || y > 2) {
            cout << "Invalid coordinates. Try again.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (matrix[x][y] != 'e') {
            cout << "Cell already occupied. Try again.\n";
            continue;
        }

        matrix[x][y] = player;
        ++moves;

        if (iswinner(matrix)) {
            printBoard(matrix);
            cout << "Player " << player << " is the winner!\n";
            return 0;
        }

        player = (player == 'o') ? 'x' : 'o';   // switch turns
    }

    printBoard(matrix);
    cout << "Game tied.\n";
    return 0;
}
