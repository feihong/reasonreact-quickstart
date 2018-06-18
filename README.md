# Feihong's ReasonReact Quickstart

# Prerequisites

    yarn global add bs-platform

# Create project

    bsb -init hello-react -theme react
    yarn install

# Commands

Build + Watch

    yarn start
    # in another tab
    npm run webpack

Build

    yarn build && yarn webpack

Build automatically inside VS Code

    Cmd+Shift+B

Run tests

    yarn test


## Run Project

```sh
yarn install
yarn start
# in another tab
yarn webpack
```

After you see the webpack compilation succeed (the `npm run webpack` step), open up `src/index.html` (**no server needed!**). Then modify whichever `.re` file in `src` and refresh the page to see the changes.


## Build for Production

```sh
yarn build
yarn webpack:production
```

This will replace the development artifact `build/Index.js` for an optimized version.

**To enable dead code elimination**, change `bsconfig.json`'s `package-specs` `module` from `"commonjs"` to `"es6"`. Then re-run the above 2 commands. This will allow Webpack to remove unused code.
