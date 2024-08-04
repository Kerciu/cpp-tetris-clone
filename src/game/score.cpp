#include "score.h"

Score::Score() : score(0)
{
}

Score::Score(int score) : score(score)
{
}

int Score::get_score()
{
    return score;
}

void Score::set_score(int score)
{
    this->score = score;
}

void Score::update_score(int rows_cleared, int move_down_points)
{
    switch(rows_cleared) {
        case 1:
            score += 100;
            break;
        case 2:
            score += 300;
            break;
        case 3:
            score += 500;
            break;
        default:
            break;
    }

    score += move_down_points;
}
