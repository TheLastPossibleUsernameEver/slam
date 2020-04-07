# SLAM Constructor & SLAM Evaluation Tools

## Карта
Карта находится в папке "map", название датасета включено в название файла карты

## Инструкция по запуску решений задач
### Настройка Workspace

Прим.: при разработке использовался дистрибутив ROS Melodic Morenia

Прим. 2: предполагается, что у вас уже установлен ROS

Прим. 3: при создании нового терминала вам необходимо добавить переменные окружения ROS:

`$ source /opt/ros/${ROS_DISTRO}/setup.bash`

#### Создайте рабочее пространство и инициализируйте его

`$ mkdir -p ~/catkin_ws/src`

`$ cd ~/catkin_ws/`

`$ catkin_make`

#### Перейдите в его папку src

`$ cd ~/catkin_ws/src`

#### Клонируйте репозиторий с кодом

`$ git clone https://github.com/TheLastPossibleUsernameEver/slam/`

#### Перейдите в корневую папку рабочего пространства и соберите исходный код

`$ catkin_make`

#### Добавьте переменные окружения проекта

`$ source devel/setup.bash`

Теперь после создания каждого нового терминала нужно добавлять переменные окружения проекта

### Запуск

Перед запуском каждого решения необходимо запустить roscore

`$ roscore`

#### 1 задача

Перейдите в папку рабочего пространства, создайте два новых терминала и введите в них

`$ rosrun slam /src/task_1/runner.py` в первом

`$ rosrun slam /src/task_1/observer.py` во втором

#### 2 задача

Откройте терминал и запустите в нём rviz

`$ rosrun rviz rviz &`

Добавьте к существующему окну в список Displays новый Display с помощью Add(By display type)>rviz>Marker

Назначьте в Global Options "Fixed Frame" значение "runner_frame"

Откройте два новых терминала и напишите в них:

`$ rosrun slam task2_runner` в одном

`$ rosrun slam task2_observer` во втором

#### 3 задача

3 задача запускается аналогично 2, только вместо task2_runner и task2_observer нужно ввести task3_runner и task3_observer

#### 4 задача

Откройте 2 терминала, и введите в них:

`$ rosrun slam src/task_4/runner.py <n>`, где n - число Runner-ов.

`$ rosrun slam src/task_4/observer.py`
