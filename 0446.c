void reset_parameters(bool win_loss, int *player_attempts, char *render_guess_lets, size_t render_guess_lets_size, bool *running_menu, char *selected_letter, char *alphabetto_check_selected_letters) {
 render_check_win_or_loss_text(win_loss);
    *running_menu = true;
    *player_attempts = 11;
    *selected_letter = '0';

    for (int i = 0; i < render_guess_lets_size - 1; i++) {
     render_guess_lets[i] = '_';
    }

    for (int i = 0; i < 26 - 1; i++) {
        alphabetto_check_selected_letters[i] = 0;
    }
}