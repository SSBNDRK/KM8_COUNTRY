# 🌍 KM8_COUNTRY

**KM8_COUNTRY** — це консольний застосунок, написаний мовою C++ з використанням бібліотек **libcurl** та **nlohmann/json**. Він дозволяє отримувати базову інформацію про країну (назву, столицю, регіон) за допомогою запиту до API [`restcountries.com`](https://restcountries.com).

---

## 🔧 Функціонал

- Введення користувачем назви країни (англійською або німецькою, наприклад: `germany`, `deutschland`)
- Надсилання HTTP-запиту через libcurl
- Парсинг відповіді у форматі JSON
- Виведення:
  - Назви країни
  - Столиці
  - Регіону

---

## 🛠 Використані технології

- C++20
- [libcurl](https://curl.se/libcurl/)
- [nlohmann/json](https://github.com/nlohmann/json)
- API: [restcountries.com](https://restcountries.com)

---

## ▶️ Приклад використання

```bash
Введіть назву країни (наприклад, germany або deutschland): germany

Результат для країни: Germany
Столиця: Berlin
Регіон: Europe
