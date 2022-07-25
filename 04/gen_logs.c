#include "gen_logs.h"

int main() {
    char ip[BUFSIZ], method[BUFSIZ], url[BUFSIZ], agent[BUFSIZ], date[BUFSIZ];
    int status = 0, index = 0, k_bytes = 0;
    for (; index < 5; ++index) {
        char filename[BUFSIZ];
        sprintf(filename, "%s_%d.log", "log", index);
        FILE *file = fopen(filename, "w");
        int n = random_ch(100, 1000);
        for (int i = 0; i < n; ++i) {
            create_agent(agent);
            create_url(url);
            create_ip(ip);
            log_time(date, index);
            status = gen_status();
            choose_method(method);
            k_bytes = random_ch(10, 10000);
            fprintf(file, "%s - username %s \"%s %s\" %d %d \"-\" \"%s\"\n", ip, date, method, url, status, k_bytes, agent);
        }
        fclose(file);
    }

    return 0;
}

void log_time(char *date, int index) {
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char month[BUFSIZ];
    month_to_stroka(month, timeinfo->tm_mon);
    sprintf(date, "[%d/%s/%d:%d:%d:%d %s]", timeinfo->tm_mday + index,
            month, timeinfo->tm_year + 1900,
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, timeinfo->tm_zone);
}

int random_ch(int min, int max) {
    int res = 0, start = 0, end = 0;
    if (min < max) {
        start = min;
        end = max + 1;
    } else {
        start = max + 1;
        end = min;
    }
    res = (rand() % (end - start)) + start;
    return res;
}

void create_ip(char *ip) {
    int ch1 = random_ch(0, 255);
    int ch2 = random_ch(0, 255);
    int ch3 = random_ch(0, 255);
    int ch4 = random_ch(0, 255);
    sprintf(ip, "%d.%d.%d.%d", ch1, ch2, ch3, ch4);
}

int gen_status() {
    int ch = random_ch(0, 9);
    return status_codes[ch];
}

void choose_method(char *method) {
    int method_num = random_ch(0, 4);
    if (method_num == 0) {
        sprintf(method, "%s", "GET");
    } else if (method_num == 1) {
        sprintf(method, "%s", "POST");
    } else if (method_num == 2) {
        sprintf(method, "%s", "PUT");
    } else if (method_num == 3) {
        sprintf(method, "%s", "PATCH");
    } else if (method_num == 4) {
        sprintf(method, "%s", "DELETE");
    }
}

void create_url(char *url) {
    int k_url = random_ch(0, 99);
    FILE *file = fopen("url.txt", "r");
    int i = 0;
    char file_stroka[BUFSIZ];
    while (NULL != fgets(file_stroka, BUFSIZ, file)) {
        if (i == k_url) {
            file_stroka[strcspn(file_stroka, "\n")] = 0;
            sprintf(url, "%s", file_stroka);
            break;
        }
        ++i;
    }
    fclose(file);
}

void create_agent(char *agent) {
    int useragent_index = random_ch(0, 199);
    FILE *file = fopen("agent.txt", "r");
    int i = 0;
    char file_stroka[BUFSIZ];
    while (NULL != fgets(file_stroka, BUFSIZ, file)) {
        if (i == useragent_index) {
            file_stroka[strcspn(file_stroka, "\n")] = 0;
            sprintf(agent, "%s", file_stroka);
            break;
        }
        ++i;
    }
    fclose(file);
}

void month_to_stroka(char *stroka, int check) {
    if (check == 0) {
        sprintf(stroka, "%s", "Jan");
    } else if (check == 1) {
        sprintf(stroka, "%s", "Feb");
    } else if (check == 2) {
        sprintf(stroka, "%s", "Mar");
    } else if (check == 3) {
        sprintf(stroka, "%s", "Apr");
    } else if (check == 4) {
        sprintf(stroka, "%s", "May");
    } else if (check == 5) {
        sprintf(stroka, "%s", "June");
    } else if (check == 6) {
        sprintf(stroka, "%s", "July");
    } else if (check == 7) {
        sprintf(stroka, "%s", "Aug");
    } else if (check == 8) {
        sprintf(stroka, "%s", "Sept");
    } else if (check == 9) {
        sprintf(stroka, "%s", "Oct");
    } else if (check == 10) {
        sprintf(stroka, "%s", "Nov");
    } else if (check == 11) {
        sprintf(stroka, "%s", "Dec");
    }
}
