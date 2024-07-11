import telebot
import json
import random
import time

question = "0"
API_TOKEN = '-'

bot = telebot.TeleBot(API_TOKEN)

@bot.message_handler(commands=['start'])
def send_welcome(message):
    bot.send_message(message.chat.id, 'Привет! Я - <b>водила-бот</b>, и я знаю, как правильно вести себя на дорогах! Хочешь так же? '
                          'Тогда напиши команду /begin и приступай к изучению правил дорожного движения! Вопросы будут'
                          'появляться каждые 30 минут!', parse_mode='html')

@bot.message_handler(commands=['help'])
def send_help(message):
    bot.send_message(message.chat.id, 'Команды:\n'
                          '/start - начать работу с ботом\n'
                          '/begin - начать рассылку\n'
                          '/info [number] - пояснение к вопросу\n'
                          '/timer [minutes] - установить время между постами (в разработке)\n'
                          '/stats - увидеть профиль и достижения (в разработке)\n')


@bot.message_handler(commands=['begin'])
def send_question(message):
    flag = True
    while flag:
        with open("data/questions.json", encoding="utf8") as file:
            data = json.load(file)
        question_number = str(random.randint(1, len(data)))

        markup = telebot.types.ReplyKeyboardMarkup(resize_keyboard=True)
        buttom_1 = telebot.types.KeyboardButton("1️⃣")
        buttom_2 = telebot.types.KeyboardButton("2️⃣")
        buttom_3 = telebot.types.KeyboardButton("3️⃣")
        markup.add(buttom_1, buttom_2, buttom_3)

        photo = open(data[question_number][5], 'rb')
        text = (question_number + '. ' + data[question_number][0] + '\n1. ' + data[question_number][1] + '\n2. '
                + data[question_number][2] + '\n3. ' + data[question_number][3])
        bot.send_photo(message.chat.id, photo, caption=text, parse_mode='HTML', reply_markup=markup)
        bot.send_message(message.chat.id, f'Правильный ответ: ||{data[question_number][4]}||',  parse_mode='MarkdownV2')

        time.sleep(1800)

# @bot.message_handler(commands=['timer'])
# def set_timer(message):
#     with open("data/users.txt", "a", encoding="utf8") as file:
#         value = message.text.split()[1]
#         file.write(str(message.from_user.id) + "-" + str(value) + '.\n')
#         bot.send_message(message.chat.id, f"Время между постами успешно установлено и равняется: {value} мин.")


@bot.message_handler(commands=['info'])
def send_info(message):
    with open("data/questions.json", encoding="utf8") as file:
        data = json.load(file)
        number = message.text.split()[1]
        bot.send_message(message.chat.id, data[number][6])

@bot.message_handler()
def confusing_reply(message):
    if message.text == "1️⃣":
        pass
    elif message.text == "2️⃣":
        pass
    elif message.text == "3️⃣":
        pass
    else:
        bot.reply_to(message, 'Не понимаю. Блокирую! Напиши /help, чтобы узнать мой функционал')


bot.infinity_polling()
