# Домашняя работа №2

1. Реализовать функццию вычисления [производной функции в заданной точке](https://ru.wikipedia.org/wiki/%D0%9F%D1%80%D0%BE%D0%B8%D0%B7%D0%B2%D0%BE%D0%B4%D0%BD%D0%B0%D1%8F_%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D0%B8)

   `double der( double(* const f)(double), const double x, const double delta)`
   
   _Функцию считать непрерывно дифференцируемой на *R*_
   
3. Разработать код для студента мехмата:
   - Направление(бакалавриат-магистратура), Курс(1-4), Группа(1-9), Номер в списке группы в алфавитном порядке(1-32);
   - Реализовать функцию кодирования `uint encode(const bool bachelor, const uint course, const uint group, const uint order)`, возвращающую уникальный код студента;
   - Реализовать функцию декодирования `void decode(const uint id, bool &bachelor, uint &course, uint &group, uint &order)`.