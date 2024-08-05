#pragma once

class Score
{
    public:
    Score();
    Score(int score);

    int get_score();
    void set_score(int score);
    void update_score_rows_cleared(int rows_cleared);
    void update_score_on_lock(int move_down_points);

    private:
    int score;
};