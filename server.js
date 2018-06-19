const express = require('express')
const app = express()
const emojione = require('emojione')

const emojis = Object.keys(emojione.emojioneList)
  .map(shortname => {
    let em = emojione.emojioneList[shortname]
    return {
      shortname: shortname.slice(1, -1),
      text: emojione.convert(em.uc_output),
      category: em.category,
    } 
  })
  .filter(em => em.category != 'flags')

app.use(express.static('public'))

function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min
}

app.get('/', (req, res) => {
  res.sendFile('./public/index.html')
})

app.get('/hanzi', (req, res) => {
  let ord = getRandomInt(0x4e00, 0x9fff)
  res.status(200).json({
    text: String.fromCodePoint(ord),
    ordinal: ord,
  })
})

app.get('/emoji', (req, res) => {
  let index = getRandomInt(0, emojis.length - 1)
  res.status(200).json(emojis[index])
})

const listener = app.listen(process.env.PORT || 8000, () => {
  console.log('Your app is listening on port ' + listener.address().port)
})