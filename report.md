# DO5_SimpleDocker

## **Part 1. Готовый докер**

- **Взять официальный докер образ с nginx и выкачать его при помощи `docker pull`**
    
    ![Untitled](images/Untitled.png)
    
- **Проверить наличие докер образа через `docker images`**
    
    ![Untitled](images/Untitled%201.png)
    
- **Запустить докер образ через `docker run -d [image_id|repository]`**
- **Проверить, что образ запустился через `docker ps`**
    
    ![Untitled](images/Untitled%202.png)
    
- **Посмотреть информацию о контейнере через `docker inspect [container_id|container_name]`**
    
    ![Untitled](images/Untitled%203.png)
    
- **По выводу команды определить и поместить в отчёт размер контейнера, список замапленных портов и ip контейнера**
    
    "ShmSize": 67108864
    
    "Ports": {"80/tcp": null}
    
    "IPAddress": "172.17.0.2”
    
- **Остановить докер образ через `docker stop [container_id|container_name]`**
    
    ![Untitled](images/Untitled%204.png)
    
- **Проверить, что образ остановился через `docker ps`**
    
    ![Untitled](images/Untitled%205.png)
    
- **Запустить докер с замапленными портами 80 и 443 на локальную машину через команду *run***
    
    ![Untitled](images/Untitled%206.png)
    
- **Проверить, что в браузере по адресу *localhost:80* доступна стартовая страница nginx**
    
    ![Untitled](images/Untitled%207.png)
    
- **Перезапустить докер образ через `docker restart [image_id|repository]`**
    
    ![Untitled](images/Untitled%208.png)
    
- **Проверить любым способом, что контейнер запустился**
    
    ![Untitled](images/Untitled%209.png)
    

## **Part 2. Операции с контейнером**

- **Прочитать конфигурационный файл *nginx.conf* внутри докер образа через команду *exec***
    
    ![Untitled](images/Untitled%2010.png)
    
- **Создать на локальной машине файл *nginx.conf***
    
    ![Untitled](images/Untitled%2011.png)
    
- **Настроить в нем по пути */status* отдачу страницы статуса сервера nginx**
    
    ![Untitled](images/Untitled%2012.png)
    
- **Скопировать созданный файл *nginx.conf* внутрь докер образа через команду `docker cp`**
    
    ![Untitled](images/Untitled%2013.png)
    
- **Перезапустить nginx внутри докер образа через команду *exec***
    
    ![Untitled](images/Untitled%2014.png)
    
- **Проверить, что по адресу *localhost:80/status* отдается страничка со статусом сервера nginx**
    
    ![Untitled](images/Untitled%2015.png)
    
- **Экспортировать контейнер в файл *container.tar* через команду *export***
    
    ![Untitled](images/Untitled%2016.png)
    
- **Остановить контейнер**
    
    ![Untitled](images/Untitled%2017.png)
    
- **Удалить образ через `docker rmi [image_id|repository]`, не удаляя перед этим контейнеры**
    
    ![Untitled](images/Untitled%2018.png)
    
- **Импортировать контейнер обратно через команду *import***
    
    ![Untitled](images/Untitled%2019.png)
    
- **Запустить импортированный контейнер**
    
    ![Untitled](images/Untitled%2020.png)
    

## ...
