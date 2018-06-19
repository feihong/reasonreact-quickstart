# Feihong's ReasonReact Quickstart

# Prerequisites

    yarn global add bs-platform

# Create project

    bsb -init hello-react -theme react
    yarn install

# Commands

Build + Watch

    yarn dev

Build

    yarn build

Build automatically inside VS Code

    Cmd+Shift+B

Run tests

    yarn test


## Run Project

```sh
yarn install
yarn dev
```

Open your browser to `http://localhost:8000`. Then modify whichever `.re` file 
in `src` and refresh the page to see the changes.


## Build for Production

```sh
yarn build
yarn webpack:production
```

This will replace the development artifact `build/Index.js` for an optimized version.

**To enable dead code elimination**, change `bsconfig.json`'s `package-specs` `module` from `"commonjs"` to `"es6"`. Then re-run the above 2 commands. This will allow Webpack to remove unused code.

## Links

[Examples for ReasonReact](https://github.com/reasonml-community/reason-react-example)