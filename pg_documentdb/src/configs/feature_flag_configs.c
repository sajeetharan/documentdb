/*-------------------------------------------------------------------------
 * Copyright (c) Microsoft Corporation.  All rights reserved.
 *
 * src/configs/feature_flag_configs.c
 *
 * Initialization of GUCs that control feature flags that will eventually
 * become defaulted and simply toggle behavior.
 *-------------------------------------------------------------------------
 */

#include <postgres.h>
#include <miscadmin.h>
#include <utils/guc.h>
#include <limits.h>
#include "configs/config_initialization.h"


/*
 * SECTION: Top level feature flags
 */
#define DEFAULT_ENABLE_SCHEMA_VALIDATION false
bool EnableSchemaValidation =
	DEFAULT_ENABLE_SCHEMA_VALIDATION;

#define DEFAULT_ENABLE_BYPASSDOCUMENTVALIDATION false
bool EnableBypassDocumentValidation =
	DEFAULT_ENABLE_BYPASSDOCUMENTVALIDATION;

#define DEFAULT_ENABLE_NATIVE_TABLE_COLOCATION false
bool EnableNativeTableColocation = DEFAULT_ENABLE_NATIVE_TABLE_COLOCATION;

#define DEFAULT_ENABLE_USERNAME_PASSWORD_CONSTRAINTS true
bool EnableUsernamePasswordConstraints = DEFAULT_ENABLE_USERNAME_PASSWORD_CONSTRAINTS;

#define DEFAULT_ENABLE_USERS_INFO_PRIVILEGES true
bool EnableUsersInfoPrivileges = DEFAULT_ENABLE_USERS_INFO_PRIVILEGES;


/*
 * SECTION: Vector Search flags
 */

/* GUC to enable HNSW index type and query for vector search. */
#define DEFAULT_ENABLE_VECTOR_HNSW_INDEX true
bool EnableVectorHNSWIndex = DEFAULT_ENABLE_VECTOR_HNSW_INDEX;

/* GUC to enable vector pre-filtering feature for vector search. */
#define DEFAULT_ENABLE_VECTOR_PRE_FILTER true
bool EnableVectorPreFilter = DEFAULT_ENABLE_VECTOR_PRE_FILTER;

#define DEFAULT_ENABLE_VECTOR_PRE_FILTER_V2 false
bool EnableVectorPreFilterV2 = DEFAULT_ENABLE_VECTOR_PRE_FILTER_V2;

#define DEFAULT_ENABLE_VECTOR_FORCE_INDEX_PUSHDOWN false
bool EnableVectorForceIndexPushdown = DEFAULT_ENABLE_VECTOR_FORCE_INDEX_PUSHDOWN;

/* GUC to enable vector compression for vector search. */
#define DEFAULT_ENABLE_VECTOR_COMPRESSION_HALF true
bool EnableVectorCompressionHalf = DEFAULT_ENABLE_VECTOR_COMPRESSION_HALF;

#define DEFAULT_ENABLE_VECTOR_COMPRESSION_PQ true
bool EnableVectorCompressionPQ = DEFAULT_ENABLE_VECTOR_COMPRESSION_PQ;

#define DEFAULT_ENABLE_VECTOR_CALCULATE_DEFAULT_SEARCH_PARAM true
bool EnableVectorCalculateDefaultSearchParameter =
	DEFAULT_ENABLE_VECTOR_CALCULATE_DEFAULT_SEARCH_PARAM;

/*
 * SECTION: Indexing feature flags
 */

/* Remove after v104 */
#define DEFAULT_ENABLE_LARGE_UNIQUE_INDEX_KEYS true
bool DefaultEnableLargeUniqueIndexKeys = DEFAULT_ENABLE_LARGE_UNIQUE_INDEX_KEYS;

/* Remove after v105 */
#define DEFAULT_ENABLE_RUM_IN_OPERATOR_FAST_PATH true
bool EnableRumInOperatorFastPath = DEFAULT_ENABLE_RUM_IN_OPERATOR_FAST_PATH;

/* Remove after v104 */
#define DEFAULT_ENABLE_INDEX_TERM_TRUNCATION_NESTED_OBJECTS true
bool EnableIndexTermTruncationOnNestedObjects =
	DEFAULT_ENABLE_INDEX_TERM_TRUNCATION_NESTED_OBJECTS;

/* Remove after v104 */
#define DEFAULT_ENABLE_INDEX_OPERATOR_BOUNDS true
bool EnableIndexOperatorBounds = DEFAULT_ENABLE_INDEX_OPERATOR_BOUNDS;

/* Remove after v105 */
#define DEFAULT_USE_UNSAFE_INDEX_TERM_TRANSFORM true
bool IndexTermUseUnsafeTransform = DEFAULT_USE_UNSAFE_INDEX_TERM_TRANSFORM;

#define DEFAULT_FORCE_RUM_ORDERED_INDEX_SCAN false
bool ForceRumOrderedIndexScan = DEFAULT_FORCE_RUM_ORDERED_INDEX_SCAN;

/*
 * SECTION: Planner feature flags
 */
#define DEFAULT_ENABLE_NEW_OPERATOR_SELECTIVITY false
bool EnableNewOperatorSelectivityMode = DEFAULT_ENABLE_NEW_OPERATOR_SELECTIVITY;

#define DEFAULT_ENABLE_RUM_INDEX_SCAN true
bool EnableRumIndexScan = DEFAULT_ENABLE_RUM_INDEX_SCAN;

#define DEFAULT_ENABLE_MULTI_INDEX_RUM_JOIN false
bool EnableMultiIndexRumJoin = DEFAULT_ENABLE_MULTI_INDEX_RUM_JOIN;

#define DEFAULT_ENABLE_SORT_BY_ID_PUSHDOWN_TO_PRIMARYKEY false
bool EnableSortbyIdPushDownToPrimaryKey =
	DEFAULT_ENABLE_SORT_BY_ID_PUSHDOWN_TO_PRIMARYKEY;

#define DEFAULT_USE_NEW_ELEMMATCH_INDEX_PUSHDOWN false
bool UseNewElemMatchIndexPushdown = DEFAULT_USE_NEW_ELEMMATCH_INDEX_PUSHDOWN;


/*
 * SECTION: Aggregation & Query feature flags
 */
#define DEFAULT_ENABLE_NOW_SYSTEM_VARIABLE false
bool EnableNowSystemVariable = DEFAULT_ENABLE_NOW_SYSTEM_VARIABLE;

/* Remove after v104 */
#define DEFAULT_ENABLE_MATCH_WITH_LET_IN_LOOKUP true
bool EnableMatchWithLetInLookup =
	DEFAULT_ENABLE_MATCH_WITH_LET_IN_LOOKUP;

#define DEFAULT_ENABLE_PRIMARY_KEY_CURSOR_SCAN false
bool EnablePrimaryKeyCursorScan = DEFAULT_ENABLE_PRIMARY_KEY_CURSOR_SCAN;

#define DEFAULT_USE_RAW_EXECUTOR_FOR_QUERY_PLAN true
bool UseRawExecutorForQueryPlan = DEFAULT_USE_RAW_EXECUTOR_FOR_QUERY_PLAN;

#define DEFAULT_USE_FILE_BASED_PERSISTED_CURSORS false
bool UseFileBasedPersistedCursors = DEFAULT_USE_FILE_BASED_PERSISTED_CURSORS;

#define DEFAULT_ENABLE_FILE_BASED_PERSISTED_CURSORS true
bool EnableFileBasedPersistedCursors = DEFAULT_ENABLE_FILE_BASED_PERSISTED_CURSORS;

#define DEFAULT_ENABLE_COMPACT_COMMAND false
bool EnableCompact = DEFAULT_ENABLE_COMPACT_COMMAND;

#define DEFAULT_EXPAND_DOLLAR_ALL_IN_QUERY_OPERATOR true
bool ExpandDollarAllInQueryOperator = DEFAULT_EXPAND_DOLLAR_ALL_IN_QUERY_OPERATOR;

#define DEFAULT_USE_LEGACY_ORDERBY_BEHAVIOR false
bool UseLegacyOrderByBehavior = DEFAULT_USE_LEGACY_ORDERBY_BEHAVIOR;

#define DEFAULT_USE_LEGACY_NULL_EQUALITY_BEHAVIOR false
bool UseLegacyNullEqualityBehavior = DEFAULT_USE_LEGACY_NULL_EQUALITY_BEHAVIOR;


/*
 * SECTION: Let support feature flags
 */
#define DEFAULT_ENABLE_LET_AND_COLLATION_FOR_QUERY_MATCH false
bool EnableLetAndCollationForQueryMatch =
	DEFAULT_ENABLE_LET_AND_COLLATION_FOR_QUERY_MATCH;

#define DEFAULT_ENABLE_VARIABLES_SUPPORT_FOR_WRITE_COMMANDS false
bool EnableVariablesSupportForWriteCommands =
	DEFAULT_ENABLE_VARIABLES_SUPPORT_FOR_WRITE_COMMANDS;


/*
 * SECTION: Collation feature flags
 */
#define DEFAULT_SKIP_FAIL_ON_COLLATION false
bool SkipFailOnCollation = DEFAULT_SKIP_FAIL_ON_COLLATION;

#define DEFAULT_ENABLE_LOOKUP_ID_JOIN_OPTIMIZATION_ON_COLLATION false
bool EnableLookupIdJoinOptimizationOnCollation =
	DEFAULT_ENABLE_LOOKUP_ID_JOIN_OPTIMIZATION_ON_COLLATION;


/*
 * SECTION: Cluster administration & DDL feature flags
 */
#define DEFAULT_RECREATE_RETRY_TABLE_ON_SHARDING false
bool RecreateRetryTableOnSharding = DEFAULT_RECREATE_RETRY_TABLE_ON_SHARDING;

#define DEFAULT_ENABLE_MERGE_TARGET_CREATION false
bool EnableMergeTargetCreation = DEFAULT_ENABLE_MERGE_TARGET_CREATION;

#define DEFAULT_ENABLE_MERGE_ACROSS_DB true
bool EnableMergeAcrossDB = DEFAULT_ENABLE_MERGE_ACROSS_DB;

/* Move to system configs after v104 */
#define DEFAULT_ENABLE_STATEMENT_TIMEOUT true
bool EnableBackendStatementTimeout = DEFAULT_ENABLE_STATEMENT_TIMEOUT;

#define ALTER_CREATION_TIME_IN_COMPLETE_UPGRADE false
bool AlterCreationTimeInCompleteUpgrade = ALTER_CREATION_TIME_IN_COMPLETE_UPGRADE;

#define DEFAULT_ENABLE_DATA_TABLES_WITHOUT_CREATION_TIME true
bool EnableDataTableWithoutCreationTime =
	DEFAULT_ENABLE_DATA_TABLES_WITHOUT_CREATION_TIME;

#define DEFAULT_ENABLE_MULTIPLE_INDEX_BUILDS_PER_RUN true
bool EnableMultipleIndexBuildsPerRun = DEFAULT_ENABLE_MULTIPLE_INDEX_BUILDS_PER_RUN;

/* Remove after v105 */
#define DEFAULT_SKIP_ENFORCE_TRANSACTION_READ_ONLY false
bool SkipEnforceTransactionReadOnly = DEFAULT_SKIP_ENFORCE_TRANSACTION_READ_ONLY;

#define DEFAULT_SKIP_CREATE_INDEXES_ON_CREATE_COLLECTION false
bool SkipCreateIndexesOnCreateCollection =
	DEFAULT_SKIP_CREATE_INDEXES_ON_CREATE_COLLECTION;

#define DEFAULT_USE_NEW_SHARD_KEY_CALCULATION true
bool UseNewShardKeyCalculation = DEFAULT_USE_NEW_SHARD_KEY_CALCULATION;

#define DEFAULT_ENABLE_BUCKET_AUTO_STAGE true
bool EnableBucketAutoStage = DEFAULT_ENABLE_BUCKET_AUTO_STAGE;

/* FEATURE FLAGS END */

void
InitializeFeatureFlagConfigurations(const char *prefix, const char *newGucPrefix)
{
	DefineCustomBoolVariable(
		psprintf("%s.enableVectorHNSWIndex", prefix),
		gettext_noop(
			"Enables support for HNSW index type and query for vector search in bson documents index."),
		NULL, &EnableVectorHNSWIndex, DEFAULT_ENABLE_VECTOR_HNSW_INDEX,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableVectorPreFilter", prefix),
		gettext_noop(
			"Enables support for vector pre-filtering feature for vector search in bson documents index."),
		NULL, &EnableVectorPreFilter, DEFAULT_ENABLE_VECTOR_PRE_FILTER,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableVectorPreFilterV2", prefix),
		gettext_noop(
			"Enables support for vector pre-filtering v2 feature for vector search in bson documents index."),
		NULL, &EnableVectorPreFilterV2, DEFAULT_ENABLE_VECTOR_PRE_FILTER_V2,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enable_force_push_vector_index", prefix),
		gettext_noop(
			"Enables ensuring that vector index queries are always pushed to the vector index."),
		NULL, &EnableVectorForceIndexPushdown, DEFAULT_ENABLE_VECTOR_FORCE_INDEX_PUSHDOWN,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableVectorCompressionHalf", newGucPrefix),
		gettext_noop(
			"Enables support for vector index compression half"),
		NULL, &EnableVectorCompressionHalf, DEFAULT_ENABLE_VECTOR_COMPRESSION_HALF,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableVectorCompressionPQ", newGucPrefix),
		gettext_noop(
			"Enables support for vector index compression product quantization"),
		NULL, &EnableVectorCompressionPQ, DEFAULT_ENABLE_VECTOR_COMPRESSION_PQ,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableVectorCalculateDefaultSearchParam", newGucPrefix),
		gettext_noop(
			"Enables support for vector index default search parameter calculation"),
		NULL, &EnableVectorCalculateDefaultSearchParameter,
		DEFAULT_ENABLE_VECTOR_CALCULATE_DEFAULT_SEARCH_PARAM,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enable_large_unique_index_keys", newGucPrefix),
		gettext_noop("Whether or not to enable large index keys on unique indexes."),
		NULL, &DefaultEnableLargeUniqueIndexKeys, DEFAULT_ENABLE_LARGE_UNIQUE_INDEX_KEYS,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableNewSelectivityMode", newGucPrefix),
		gettext_noop(
			"Determines whether to use the new selectivity logic."),
		NULL, &EnableNewOperatorSelectivityMode,
		DEFAULT_ENABLE_NEW_OPERATOR_SELECTIVITY,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableRumIndexScan", newGucPrefix),
		gettext_noop(
			"Allow rum index scans."),
		NULL,
		&EnableRumIndexScan,
		DEFAULT_ENABLE_RUM_INDEX_SCAN,
		PGC_USERSET,
		0,
		NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableRumInOperatorFastPath", newGucPrefix),
		gettext_noop(
			"Allow rum in operator fast path."),
		NULL,
		&EnableRumInOperatorFastPath,
		DEFAULT_ENABLE_RUM_IN_OPERATOR_FAST_PATH,
		PGC_USERSET,
		0,
		NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableMergeTargetCreation", newGucPrefix),
		gettext_noop(
			"Enables support for target collection creation."),
		NULL, &EnableMergeTargetCreation, DEFAULT_ENABLE_MERGE_TARGET_CREATION,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableMergeAcrossDB", newGucPrefix),
		gettext_noop(
			"Enables support for merge stage."),
		NULL, &EnableMergeAcrossDB, DEFAULT_ENABLE_MERGE_ACROSS_DB,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableSchemaValidation", prefix),
		gettext_noop(
			"Whether or not to support schema validation."),
		NULL,
		&EnableSchemaValidation,
		DEFAULT_ENABLE_SCHEMA_VALIDATION,
		PGC_USERSET,
		0,
		NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableBypassDocumentValidation", prefix),
		gettext_noop(
			"Whether or not to support 'bypassDocumentValidation'."),
		NULL,
		&EnableBypassDocumentValidation,
		DEFAULT_ENABLE_BYPASSDOCUMENTVALIDATION,
		PGC_USERSET,
		0,
		NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableMultiIndexRumJoin", newGucPrefix),
		gettext_noop(
			"Whether or not to add the cursors on aggregation style queries."),
		NULL,
		&EnableMultiIndexRumJoin,
		DEFAULT_ENABLE_MULTI_INDEX_RUM_JOIN,
		PGC_USERSET,
		0,
		NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.recreate_retry_table_on_shard", prefix),
		gettext_noop(
			"Gets whether or not to recreate a retry table to match the main table"),
		NULL, &RecreateRetryTableOnSharding, DEFAULT_RECREATE_RETRY_TABLE_ON_SHARDING,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableNativeTableColocation", prefix),
		gettext_noop(
			"Determines whether to turn on colocation of tables across all tables (requires enableNativeColocation to be on)"),
		NULL, &EnableNativeTableColocation, DEFAULT_ENABLE_NATIVE_TABLE_COLOCATION,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableIndexTermTruncationOnNestedObjects", newGucPrefix),
		gettext_noop(
			"Determines whether to truncate index terms with nested objects (arrays/objects of arrays/objects)"),
		NULL, &EnableIndexTermTruncationOnNestedObjects,
		DEFAULT_ENABLE_INDEX_TERM_TRUNCATION_NESTED_OBJECTS,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.skipFailOnCollation", newGucPrefix),
		gettext_noop(
			"Determines whether we can skip failing when collation is specified but collation is not supported"),
		NULL, &SkipFailOnCollation, DEFAULT_SKIP_FAIL_ON_COLLATION,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableLookupIdJoinOptimizationOnCollation", newGucPrefix),
		gettext_noop(
			"Determines whether we can perform _id join opetimization on collation. It would be a customer input confiriming that _id does not contain collation aware data types (i.e., UTF8 and DOCUMENT)."),
		NULL, &EnableLookupIdJoinOptimizationOnCollation,
		DEFAULT_ENABLE_LOOKUP_ID_JOIN_OPTIMIZATION_ON_COLLATION,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableNowSystemVariable", newGucPrefix),
		gettext_noop(
			"Enables support for the $$NOW time system variable."),
		NULL, &EnableNowSystemVariable,
		DEFAULT_ENABLE_NOW_SYSTEM_VARIABLE,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableStatementTimeout", newGucPrefix),
		gettext_noop(
			"Whether to enable per statement backend timeout override in the backend."),
		NULL, &EnableBackendStatementTimeout, DEFAULT_ENABLE_STATEMENT_TIMEOUT,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableSortbyIdPushDownToPrimaryKey", newGucPrefix),
		gettext_noop(
			"Whether to push down sort by id to primary key"),
		NULL, &EnableSortbyIdPushDownToPrimaryKey,
		DEFAULT_ENABLE_SORT_BY_ID_PUSHDOWN_TO_PRIMARYKEY,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableMatchWithLetInLookup", newGucPrefix),
		gettext_noop(
			"Whether or not to inline $match with lookup let variables."),
		NULL, &EnableMatchWithLetInLookup,
		DEFAULT_ENABLE_MATCH_WITH_LET_IN_LOOKUP,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableLetAndCollationForQueryMatch", newGucPrefix),
		gettext_noop(
			"Whether or not to enable collation and let for query match."),
		NULL, &EnableLetAndCollationForQueryMatch,
		DEFAULT_ENABLE_LET_AND_COLLATION_FOR_QUERY_MATCH,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableVariablesSupportForWriteCommands", newGucPrefix),
		gettext_noop(
			"Whether or not to enable let variables and $$NOW support for write (update, delete, findAndModify) commands. Only support for delete is available now."),
		NULL, &EnableVariablesSupportForWriteCommands,
		DEFAULT_ENABLE_VARIABLES_SUPPORT_FOR_WRITE_COMMANDS,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableindexboundsoperators", newGucPrefix),
		gettext_noop(
			"Whether or not to enable in indexbounds tracking for partial filter expressions."),
		NULL, &EnableIndexOperatorBounds,
		DEFAULT_ENABLE_INDEX_OPERATOR_BOUNDS,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enablePrimaryKeyCursorScan", newGucPrefix),
		gettext_noop(
			"Whether or not to enable primary key cursor scan for streaming cursors."),
		NULL, &EnablePrimaryKeyCursorScan,
		DEFAULT_ENABLE_PRIMARY_KEY_CURSOR_SCAN,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.useRawExecutorForQueryPlan", newGucPrefix),
		gettext_noop(
			"Whether or not to enable using the raw executor for query plans."),
		NULL, &UseRawExecutorForQueryPlan,
		DEFAULT_USE_RAW_EXECUTOR_FOR_QUERY_PLAN,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.alterCreationTimeInCompleteUpgrade", newGucPrefix),
		gettext_noop(
			"alter creation_time of data table."),
		NULL, &AlterCreationTimeInCompleteUpgrade,
		ALTER_CREATION_TIME_IN_COMPLETE_UPGRADE,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.indexTermUseUnsafeTransform", newGucPrefix),
		gettext_noop(
			"use the unsafe transform for index term elements."),
		NULL, &IndexTermUseUnsafeTransform,
		DEFAULT_USE_UNSAFE_INDEX_TERM_TRANSFORM,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableUsernamePasswordConstraints", newGucPrefix),
		gettext_noop(
			"Determines whether username and password constraints are enabled."),
		NULL, &EnableUsernamePasswordConstraints,
		DEFAULT_ENABLE_USERNAME_PASSWORD_CONSTRAINTS,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.skipEnforceTransactionReadOnly", newGucPrefix),
		gettext_noop(
			"Whether or not to skip enforcing transaction read only."),
		NULL, &SkipEnforceTransactionReadOnly,
		DEFAULT_SKIP_ENFORCE_TRANSACTION_READ_ONLY,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableDataTableWithoutCreationTime", newGucPrefix),
		gettext_noop(
			"Create data table without creation_time column."),
		NULL, &EnableDataTableWithoutCreationTime,
		DEFAULT_ENABLE_DATA_TABLES_WITHOUT_CREATION_TIME,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableMultipleIndexBuildsPerRun", newGucPrefix),
		gettext_noop(
			"Whether or not to enable multiple index builds per run."),
		NULL, &EnableMultipleIndexBuildsPerRun,
		DEFAULT_ENABLE_MULTIPLE_INDEX_BUILDS_PER_RUN,
		PGC_USERSET, 0, NULL, NULL, NULL
		);

	DefineCustomBoolVariable(
		psprintf("%s.skipCreateIndexesOnCreateCollection", newGucPrefix),
		gettext_noop(
			"Whether or not to skip creating indexes on create collection."),
		NULL, &SkipCreateIndexesOnCreateCollection,
		DEFAULT_SKIP_CREATE_INDEXES_ON_CREATE_COLLECTION,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.useFileBasedPersistedCursors", newGucPrefix),
		gettext_noop(
			"Whether or not to use file based persisted cursors."),
		NULL, &UseFileBasedPersistedCursors,
		DEFAULT_USE_FILE_BASED_PERSISTED_CURSORS,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableFileBasedPersistedCursors", newGucPrefix),
		gettext_noop(
			"Whether or not to enable file based persisted cursors."),
		NULL, &EnableFileBasedPersistedCursors,
		DEFAULT_ENABLE_FILE_BASED_PERSISTED_CURSORS,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableCompact", newGucPrefix),
		gettext_noop(
			"Whether or not to enable compact command."),
		NULL, &EnableCompact,
		DEFAULT_ENABLE_COMPACT_COMMAND,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.expandDollarAllInQueryOperator", newGucPrefix),
		gettext_noop(
			"Whether or not to expand $all in query operator."),
		NULL, &ExpandDollarAllInQueryOperator,
		DEFAULT_EXPAND_DOLLAR_ALL_IN_QUERY_OPERATOR,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableUsersInfoPrivileges", newGucPrefix),
		gettext_noop(
			"Determines whether the usersInfo command returns privileges."),
		NULL, &EnableUsersInfoPrivileges,
		DEFAULT_ENABLE_USERS_INFO_PRIVILEGES,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.useNewShardKeyCalculation", newGucPrefix),
		gettext_noop(
			"Whether or not to use the new shard key calculation logic."),
		NULL, &UseNewShardKeyCalculation,
		DEFAULT_USE_NEW_SHARD_KEY_CALCULATION,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.useLegacyOrderByBehavior", newGucPrefix),
		gettext_noop(
			"Whether or not to use legacy order by behavior."),
		NULL, &UseLegacyOrderByBehavior,
		DEFAULT_USE_LEGACY_ORDERBY_BEHAVIOR,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.useLegacyNullEqualityBehavior", newGucPrefix),
		gettext_noop(
			"Whether or not to use legacy null equality behavior."),
		NULL, &UseLegacyNullEqualityBehavior,
		DEFAULT_USE_LEGACY_NULL_EQUALITY_BEHAVIOR,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.useNewElemMatchIndexPushdown", newGucPrefix),
		gettext_noop(
			"Whether or not to use the new elemMatch index pushdown logic."),
		NULL, &UseNewElemMatchIndexPushdown,
		DEFAULT_USE_NEW_ELEMMATCH_INDEX_PUSHDOWN,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.enableBucketAutoStage", newGucPrefix),
		gettext_noop(
			"Whether to enable the $bucketAuto stage."),
		NULL, &EnableBucketAutoStage,
		DEFAULT_ENABLE_BUCKET_AUTO_STAGE,
		PGC_USERSET, 0, NULL, NULL, NULL);

	DefineCustomBoolVariable(
		psprintf("%s.forceRumOrderedIndexScan", newGucPrefix),
		gettext_noop(
			"Whether to force RUM ordered index scan for rum indexes."),
		NULL, &ForceRumOrderedIndexScan,
		DEFAULT_FORCE_RUM_ORDERED_INDEX_SCAN,
		PGC_USERSET, 0, NULL, NULL, NULL);
}
