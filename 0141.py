import flet as ft


def main(page: ft.Page):
    page.title = "Простая программа 🤖"
    page.theme_mode = "black"

    text1 = ft.Text(value="Первый текст ⭐️")
    text2 = ft.Text(value="Это уже второй текст!", color="red")
    text3 = ft.Text(value="И еще один текст 😆", color="green")
    text4 = ft.Text(value="Последний текст, конец.", color="purple")
    page.controls.append(text1); page.controls.append(text2)
    page.controls.append(text3); page.controls.append(text4)

    page.update()


ft.run(main)