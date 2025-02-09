### **Бінарне дерево**
Бінарне дерево — це структура даних, у якій кожен вузол має не більше двох дочірніх вузлів: **лівий** (менші значення) та **правий** (більші значення). У бінарному дереві пошуку елементи впорядковані так, що дублювання значень не допускається.

### **Основний функціонал:**
1. **Додавання елементів (`Insert`)**  
   - Елемент додається до дерева, враховуючи його значення. Якщо значення вже існує, воно не додається (запобігання дублюванню).

2. **Пошук елемента (`Find`)**  
   - Використовується бінарний пошук для знаходження потрібного елемента. Повертається вказівник на знайдений елемент.

3. **Видалення елементів (`Delete`)**  
   - Видаляє вузол із дерева, враховуючи три можливих випадки:
     - Вузол без дітей.
     - Вузол із одним дочірнім вузлом.
     - Вузол із двома дочірніми вузлами (заміна вузла мінімальним елементом із правого піддерева).

4. **Очищення дерева (`Clear`)**  
   - Видаляє всі вузли дерева рекурсивно.

5. **Розмір дерева (`Size`)**  
   - Рекурсивно обчислює кількість вузлів у дереві.

6. **Обхід вузлів (`DoForAllElements`)**  
   - Приймає функцію як аргумент і виконує її для кожного елемента дерева (за порядком обходу).

7. **Копіювання дерева (`CopyTree`)**  
   - Рекурсивно створює копію дерева.

8. **Знаходження мінімального вузла (`FindMinimum`)**  
   - Рекурсивно або ітеративно знаходить мінімальний елемент у дереві.

---

### **Сильні сторони:**
- **Рекурсивність:** Використання рекурсії для копіювання дерева, видалення піддерев, обходу елементів.
- **Робота з пам'яттю:** Ви звільняєте пам'ять у деструкторі та в методі `Clear`, що допомагає уникнути витоків пам'яті.
- **Універсальність:** Використання шаблонів (`template<typename T>`) дозволяє працювати з будь-якими типами даних.

