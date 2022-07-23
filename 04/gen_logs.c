#include "gen_logs.h"

int main() {
    char ip[BUFSIZ], method[BUFSIZ], url[BUFSIZ], useragent[BUFSIZ], datetime[BUFSIZ];
    int status = 0, log_index = 0, bytes = 0;
    for (; log_index < 5; log_index++) {
        char file_name[BUFSIZ];
        sprintf(file_name, "%s_%d.log", "log", log_index);
        FILE *file = fopen(file_name, "w");
        int max = random_number(100, 1000);
        for (int i = 0; i < max; i++) {
            create_random_useragent(useragent);
            create_random_url(url);
            create_random_ip(ip);
            format_time(datetime, log_index);
            status = get_random_status();
            get_random_method(method);
            bytes = random_number(10, 10000);
            fprintf(file, "%s - username %s \"%s %s\" %d %d \"-\" \"%s\"\n", ip, datetime, method, url, status, bytes, useragent);
        }
        fclose(file);
    }

    return 0;
}

void format_time(char *datetime, int log_index) {
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char month[BUFSIZ];
    month_to_string(month, timeinfo->tm_mon);
    sprintf(datetime, "[%d/%s/%d:%d:%d:%d %s]", timeinfo->tm_mday + log_index,
            month, timeinfo->tm_year + 1900,
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, timeinfo->tm_zone);
}

int random_number(int min_num, int max_num) {
    int result = 0, low_num = 0, hi_num = 0;
    if (min_num < max_num) {
        low_num = min_num;
        hi_num = max_num + 1;
    } else {
        low_num = max_num + 1;
        hi_num = min_num;
    }
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

void create_random_ip(char *ip_string) {
    int d1 = random_number(0, 255);
    int d2 = random_number(0, 255);
    int d3 = random_number(0, 255);
    int d4 = random_number(0, 255);
    sprintf(ip_string, "%d.%d.%d.%d", d1, d2, d3, d4);
}

int get_random_status() {
    int index = random_number(0, 9);
    return status_codes[index];
}

void get_random_method(char *method) {
    int method_number = random_number(0, 4);
    if (method_number == 0) {
        sprintf(method, "%s", "GET");
    } else if (method_number == 1) {
        sprintf(method, "%s", "POST");
    } else if (method_number == 2) {
        sprintf(method, "%s", "PUT");
    } else if (method_number == 3) {
        sprintf(method, "%s", "PATCH");
    } else if (method_number == 4) {
        sprintf(method, "%s", "DELETE");
    }
}

void create_random_url(char *url) {
    int url_index = random_number(0, 99);
    FILE *file = fopen("urls.txt", "r");
    int i = 0;
    char file_string[BUFSIZ];
    while (NULL != fgets(file_string, BUFSIZ, file)) {
        if (i == url_index) {
            file_string[strcspn(file_string, "\n")] = 0;
            sprintf(url, "%s", file_string);
            break;
        }
        i++;
    }
    fclose(file);
}

void create_random_useragent(char *useragent) {
    int useragent_index = random_number(0, 199);
    FILE *file = fopen("agents.txt", "r");
    int i = 0;
    char file_string[BUFSIZ];
    while (NULL != fgets(file_string, BUFSIZ, file)) {
        if (i == useragent_index) {
            file_string[strcspn(file_string, "\n")] = 0;
            sprintf(useragent, "%s", file_string);
            break;
        }
        i++;
    }
    fclose(file);
}

void month_to_string(char *string, int index) {
    if (index == 0) {
        sprintf(string, "%s", "Jan");
    } else if (index == 1) {
        sprintf(string, "%s", "Feb");
    } else if (index == 2) {
        sprintf(string, "%s", "Mar");
    } else if (index == 3) {
        sprintf(string, "%s", "Apr");
    } else if (index == 4) {
        sprintf(string, "%s", "May");
    } else if (index == 5) {
        sprintf(string, "%s", "June");
    } else if (index == 6) {
        sprintf(string, "%s", "July");
    } else if (index == 7) {
        sprintf(string, "%s", "Aug");
    } else if (index == 8) {
        sprintf(string, "%s", "Sept");
    } else if (index == 9) {
        sprintf(string, "%s", "Oct");
    } else if (index == 10) {
        sprintf(string, "%s", "Nov");
    } else if (index == 11) {
        sprintf(string, "%s", "Dec");
    }
}
