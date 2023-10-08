#include <sqlite_orm/sqlite_orm.h>
#include <catch2/catch_all.hpp>

using namespace sqlite_orm;

TEST_CASE("statement_serializer using_fts5") {
    struct Post {
        std::string title;
        std::string body;
    };
    internal::db_objects_tuple<> storage;
    internal::serializer_context<internal::db_objects_tuple<>> context{storage};
    auto node = using_fts5(make_column("title", &Post::title), make_column("body", &Post::body));
    auto value = serialize(node, context);
    REQUIRE(value == "USING FTS5(\"title\", \"body\")");
}