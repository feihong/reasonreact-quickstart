const fs = require('fs')
const module_ = process.argv[2]

if (module_) {
  const orig = fs.readFileSync('./bsconfig.json', 'utf8')
  const new_ = orig.replace(/"module": ".*",/, `"module": "${module_}",`)
  fs.writeFileSync('./bsconfig.json', new_, 'utf8')
  console.log(`Changed package-spec/module to ${module_}`)
}
