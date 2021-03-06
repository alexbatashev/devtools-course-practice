# Лабораторная работа #2: Разработка библиотеки

-----

  - [Цели](#цели)
  - [Задачи](#задачи)
  - [Типичные ошибки](#типичные-ошибки)
  - [Детальные инструкции](#детальные-инструкции)
    - [Предварительная настройка](#предварительная-настройка)
    - [Выполнение лабораторной](#выполнение-лабораторной)

-----

<!-- TODO

  - Покрытие кода должно оставаться 100%.

-->

## Цели

  1. Приобрести навыки создания сброчных скриптов CMake.
  1. Познакомиться с примером стиля кодирования на языке С++ на примере
     [Google C++ Style Guide][cppguide].
  1. Углубить следующие навыки:
     - Написание unit-тестов при помощи инструмента Google Test.
     - Взаимодействие с системой непрерывной интеграции Travis.
     - Прохождение инспекции кода (code review) на GitHub.

## Задачи

  1. Нужно будет выбрать тему из [списка][topics] и создать модуль, реализующий данный функционал. Модуль должен будет иметь:
      - Качественный API, оформленный в виде заголовочного файла.
      - Набор unit-тестов, дающий 100% покрытие кода.
      - Реализацию на языке С++, с целью сборки его в виде статической библиотеки.
  1. Интегрировать свой код в основую ветвь разработки, пройдя тестирование и
     рецензию кода.

## Типичные ошибки

  1. Работу следует осуществлять только в своей личной директории.
  1. Позаботьтесь о качестве вашего кода и API в особенности. Давайте понятные
     имена своим переменным, не используйте сокращений, отделяйте логически
     несвязанные блоки кода пустыми строками, и так далее.
  1. В этой лабораторной работе не нужно добавлять приложений, использующих ваш класс. Никаких сэмплов и функций `main`, только сборка с тестами. Тесты — это лучшая иллюстрация работы с вашим классом, это "исполняемая документация".
  1. Оформление тестов:
     - Во всех тестах должны быть явные секции Arrange, Act, Assert.
     - Как правило должна быть только одна конструкция Assert.
     - Тесты должны читаться как реальный код, должны проверяться осмысленные
       пользовательские сценарии, давайте переменным осмысленные и понятные имена.
  1. Не заливайте никаких лишних файлов:
    - Бинарные файлы (результат компиляции)
    - Проекты, сгенерированные CMake (Microsoft Visual Studio и другие)

## Детальные инструкции

### Предварительная настройка

  1. Выберите себе тему лабораторной из [списка][topics], вписав свое имя и группу в еще свободную клетку таблицы. Также, придумайте краткое название для своего модуля, отражающее его суть.

  1. Перед выполнением лабораторной работы получите последнюю версию кодов из репозитория. Вот [примерные инструкции][git-pull] как добавить `upstream` репозиторий и обновиться до актуального состояния.

        $ cd devtools-course-practice
        $ git checkout master
        $ git fetch upstream
        $ git merge upstream/master
        $ git checkout -b lab2-YOUR-NAME

  1. Далее полезно убедиться, что проект успешно собирается и проходит все
  тесты. Для этого можно как и ранее можно запустить в командной строке
  следующую команду:

        $ ctest -VV -S devtools_test.cmake

  1. Следующим шагом стоит построить и запустить проект в IDE. Откройте среду по выбору (это может быть CLion, Qt Creator или Visual Studio, текстовые редакторы Visual Studio Code или Atom) и в ней откройте наш проект. Необходимо указать на файл `CMakeLists.txt`, находящийся в корневой директории. В браузере проекта (панель слева) должен появиться проект-пример, структуру которого стоит изучить. Также стоит запустить модуль с тестами, и убедиться, что они проходят.

Далее можно приступать к выполнению собственно лабораторной работы.

### Выполнение лабораторной

  1. Создайте новую директорию для своего модуля. Его необходимо расположить в
     директории `modules` и дать ему имя, отражающее суть проекта.
  1. Далее создайте в своей директории структуру, аналогичную той, что показана
     в проекте-примере (`complex-number`). У вас должны появиться
     три директории: `include`, `src` и `test`.
  1. Затем скопируйте файл `CMakeLists.txt` из модуля `complex-number` и
     модифицируйте его под свой проект, если это будет необходимо.
  1. Затем разработайте интерфейс класса (h-файл), и поместите его в папку
     `include`. Это самая ответственная часть данной лабораторной работы.
     - __Необходимо придумать простой, понятный и удобный интерфейс для своего
       класса. Возможно потребуется сделать несколько итераций, потратьте на это
       время.__
     - Постарайтесь избегать лишних зависимостей в своем заголовочном файле.
     - Также желательно предоставлять минималистичный публичный интерфейс
       (секция `public`), позволяющий решить задачу, а все остальное поместить в
       `private` секцию класса (или `protected`).
  1. Затем необходимо реализовать ваш класс и положить исходный код в директорию
     `src`.
     - Также вы должны положить сюда еще один файл `CMakeLists.txt`, описывающий
       построение вашего модуля. Его можно создать по примеру файла
       `complex-number/src/CMakeLists.txt`.
  1. После этого следует покрыть API вашего класса тестами. Нужно протестировать
     каждый публичный метод, на корректный и некорректный ввод. Когда вы пошлете
     пулл реквест, Travis и система Codecov сообщат покрытие для вашего
     модуля. По результатам покрытие должно быть 100%, если у вас получилось
     меньше, нужно вернуться и добавить тестов.
     - В директории `test` тоже должен быть свой `CMakeLists.txt`, описывающий
       модуль с тестами.
     - Не забудьте также положить файл с функцией `main`. Его можно
       позаимствовать из директории `complex-number/test`.
     - __Важное замечание:__ во время написания тестов вам может показаться, что
       API вашего класса неудобен и его можно улучшить. В таком случае нужно
       вернуться и переделать API.
  1. Когда все будет готово, нужно снова прислать пулл-реквест.
     - Как и всегда, первым делом стоит добиться "зеленого" билда от Travis CI.
       Убедитесь, что ваш модуль построился и тесты на него были запущены и
       успешно прошли.
     - Скорее всего будет масса замечаний от скрипта `cpplint.py`, проверяющего
       стиль кодирования. Замечания нужно исправить и сделать коммиты в ту же
       ветку, пулл реквест обновится автоматически.
     - Когда вы добъетесь "зеленого" билда на Travis, необходимо получить
       одобрение от двух сокурсников в виде `+1`. После этого пригласите на проверку
       преподавателей.

__ВНИМАНИЕ РЕЦЕНЗЕНТОВ__: как бы прекрасно ни была сделана лабораторная, вы _обязаны_ попросить какой-нибудь ее доработки. В лучшем случае это будут найденные вами баги, как минимум -- какие-то другие мелкие запросы, например переименование или изменение форматирования. Но вы обязаны оправить автора что-то доделать, чтобы он добавил коммитов и пулл-реквест прошел еще одно тестирование.

После того, как ваши коды окажутся в центральном репозитории, лабораторную можно
считать выполненной.

<!-- LINKS -->

[git-pull]: https://groups.google.com/d/msg/devtools-course/V8rtlLrCXc4/k7vx6BxnqR4J
[topics]: https://docs.google.com/spreadsheets/d/1m5rS9Faw9btVamYrwWCAzIUgrL-EvZgkaOg4tUHhmO0/edit#gid=850734140
[cppguide]: http://google.github.io/styleguide/cppguide.html
