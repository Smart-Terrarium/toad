# Branch naming conventions

## Examples of branch names
* **feature** is for adding, refactoring or removing a feature
* **bugfix** is for fixing a bug
* **hotfix** is for changing code with a temporary solution and/or without following the usual process (usually because of an emergency)
* **test** is for experimenting outside of an issue/ticket


```bash
# general example
git checkout -b <category/reference/description-in-kebab-case>
# for github issue
git checkout -b feature/github-XX
# for zenhub issue
git checkout -b feature/zenhub-XX
# if issue is not officially specified
git checkout -b feature/create-new-button-component
```
