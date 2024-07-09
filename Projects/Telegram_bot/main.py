import telebot
import json
import random

with open("data/questions.json", encoding="utf8") as file:
    data = json.load(file)

API_TOKEN = '6870856711:AAFzbi7CVl40MIcCl8weF_P8jPvW3BU5xo4'

bot = telebot.TeleBot(API_TOKEN)

@bot.message_handler(commands=['start'])
def send_welcome(message):
    bot.send_message(message.chat.id, 'Привет! Я - <b>водила-бот</b>, и я знаю, как правильно вести себя на дорогах! Хочешь так же? '
                          'Тогда напиши команду /question и приступай к изучению правил дорожного движения!', parse_mode='html')

@bot.message_handler(commands=['help'])
def send_help(message):
    bot.send_message(message.chat.id, 'Команды:\n'
                          '/start - начать работу с ботом\n'
                          '/question - получить вопрос\n'
                          '/stats - увидеть профиль и достижения\n')

@bot.message_handler(commands=['question'])
def send_question(message):
    question_number = str(random.randint(0, len(data)))
    markup = telebot.types.ReplyKeyboardMarkup(resize_keyboard=True)
    photo = open(data[question_number][5], 'rb')
    buttom_1 = telebot.types.KeyboardButton(data[question_number][1])
    buttom_2 = telebot.types.KeyboardButton(data[question_number][2])
    buttom_3 = telebot.types.KeyboardButton(data[question_number][3])
    markup.add(buttom_1, buttom_2, buttom_3)
    bot.send_photo(message.chat.id, photo)
    bot.send_message(message.chat.id, data[question_number][0], reply_markup=markup)


@bot.message_handler()
def confusing_reply(message):
    bot.reply_to(message, 'Хуйню какую-то пишешь... Попробуй /help')


bot.infinity_polling()