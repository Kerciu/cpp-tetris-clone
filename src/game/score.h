#pragma once

class Score
{
    public:
    Score();
    Score(int score);

    int get_score();
    void set_score(int score);
    void update_score(int rows_cleared, int move_down_points);

    private:
    int score;
};