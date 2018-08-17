const path = require('path')
const glob = require('glob')
const outputDir = path.join(__dirname, "public/");

const mode = process.env.NODE_ENV === 'production'
  ? 'production' : 'development';

let cfg = [
  {
    mode,
    entry: './src/Index.bs.js',
    output: {
      path: outputDir,
      publicPath: outputDir,
      filename: 'bundle.js',
    },
  },
]

if (mode === 'development') {
  const testDir = './tests/'
  const outputDir = path.join(__dirname, '__tests__')
  const entries =
    glob.sync(testDir + '*_test.bs.js')
      .reduce((acc, path_) => {
        let name = path_.substring(testDir.length, path_.length - 6)
        return { ...acc, [name]: path_ }
      }, {})

  // console.log(entries);
  cfg.push({
    mode,
    entry: entries,
    output: {
      path: outputDir,
      publicPath: outputDir,
      filename: '[name].js',
    }
  })
}

module.exports = cfg
